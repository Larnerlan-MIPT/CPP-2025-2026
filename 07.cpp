#include <queue>
#include <vector>
#include <utility>
#include "image.hpp"

using Point = std::pair<int, int>;

const Pixel WHITE = {255, 255, 255};
const Pixel BLACK = {0, 0, 0};
const Pixel GREEN = {0, 255, 0};
const Pixel RED = {255, 0, 0};
const Pixel BLUE = {0, 0, 255};

int main() {
    Image image("input.ppm");
    int w = image.Width();
    int h = image.Height();

    Point start = {-1, -1}, end = {-1, -1};
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            Pixel p = image.GetPixel(x, y);
            if (p == GREEN) start = {x, y};
            if (p == RED) end = {x, y};
        }
    }

    if (start.first == -1 || end.first == -1) return 0;

    std::vector<std::vector<int>> dist(h, std::vector<int>(w, -1));
    std::vector<std::vector<Point>> parent(h, std::vector<Point>(w, {-1, -1}));
    std::queue<Point> q;

    dist[start.second][start.first] = 0;
    q.push(start);

    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        if (cur == end) break;

        for (int i = 0; i < 8; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                Pixel pix = image.GetPixel(nx, ny);
                if (pix != BLACK && dist[ny][nx] == -1) {
                    dist[ny][nx] = dist[cur.second][cur.first] + 1;
                    parent[ny][nx] = cur;
                    q.push({nx, ny});
                }
            }
        }
    }

    if (dist[end.second][end.first] == -1) return 0;

    Point cur = end;
    while (cur != start) {
        if (cur != end) {
            image.SetPixel(cur.first, cur.second, BLUE);
        }
        cur = parent[cur.second][cur.first];
    }

    image.Save("output.ppm");
    return 0;
}