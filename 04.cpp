#include <iostream>
#include <string>
#include <vector>
#include <future>
#include <cstdint>
#include "image.hpp"

struct Color { uint8_t r, g, b; };

Color averageColor(const Image& img)
{
    uint64_t sumR = 0, sumG = 0, sumB = 0;
    uint64_t total = static_cast<uint64_t>(img.width()) * img.height();
    for (int y = 0; y < img.height(); ++y)
        for (int x = 0; x < img.width(); ++x)
        {
            auto pixel = img(x, y);
            sumR += pixel.r;
            sumG += pixel.g;
            sumB += pixel.b;
        }
    return { static_cast<uint8_t>(sumR / total),
             static_cast<uint8_t>(sumG / total),
             static_cast<uint8_t>(sumB / total) };
}

class ImageLoader
{
public:
    static Image load(const std::string& filename)
    {
        std::ifstream file(filename, std::ios::binary);
        if (!file) throw std::runtime_error("File not found");
        // далее код загрузки PPM, предполагается готовый в image.hpp
        return Image(file);
    }
};

int main()
{
    std::vector<std::future<std::string>> results;
    std::string filename;
    while (true)
    {
        std::cout << "Enter image name: ";
        std::cin >> filename;
        if (filename == "quit") break;
        results.emplace_back(std::async(std::launch::async, [filename]() -> std::string {
            try {
                Image img = ImageLoader::load(filename);
                Color avg = averageColor(img);
                return "Average color of " + filename + " is: (" +
                       std::to_string(avg.r) + ", " +
                       std::to_string(avg.g) + ", " +
                       std::to_string(avg.b) + ")";
            } catch (...) {
                return "File " + filename + " do not exist";
            }
        }));
    }
    for (auto& f : results)
        std::cout << f.get() << std::endl;
}