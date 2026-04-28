#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

enum class State { Blocked, Unblocked, Activated };

class Node : public std::enable_shared_from_this<Node>
{
protected:
    sf::Sprite icon;
    std::vector<std::shared_ptr<Node>> children;
    State state = State::Blocked;
public:
    Node(const sf::Texture& tex) { icon.setTexture(tex); }
    virtual ~Node() = default;
    void addChild(std::shared_ptr<Node> c) { children.push_back(c); }
    virtual void onClick(int x, int y, int& points) = 0;
    virtual void draw(sf::RenderWindow& w, int x, int y) = 0;
    void setState(State s) { state = s; }
    State getState() const { return state; }
};

class HitNode : public Node
{
public:
    using Node::Node;
    void onClick(int x, int y, int& points) override
    {
        if (state == State::Unblocked && points > 0)
        {
            state = State::Activated;
            --points;
            for (auto& c : children) if (c->getState() == State::Blocked) c->setState(State::Unblocked);
        }
        else if (state == State::Activated)
        {
            state = State::Unblocked;
            ++points;
            for (auto& c : children) c->setState(State::Blocked);
        }
    }
    void draw(sf::RenderWindow& w, int x, int y) override { icon.setPosition(x, y); w.draw(icon); }
};

class AccumulativeNode : public Node
{
    int level = 0;
    int maxLevel;
public:
    AccumulativeNode(const sf::Texture& tex, int maxlvl) : Node(tex), maxLevel(maxlvl) {}
    void onClick(int x, int y, int& points) override
    {
        if (state == State::Unblocked && points > 0)
        {
            state = State::Activated;
            level = 1;
            --points;
            for (auto& c : children) if (c->getState() == State::Blocked) c->setState(State::Unblocked);
        }
        else if (state == State::Activated)
        {
            bool left = true; // упрощение: всегда левая для примера
            if (left && level < maxLevel && points > 0)
            {
                ++level;
                --points;
            }
            else
            {
                --level;
                ++points;
                if (level == 0)
                {
                    state = State::Unblocked;
                    for (auto& c : children) c->setState(State::Blocked);
                }
            }
        }
    }
    void draw(sf::RenderWindow& w, int x, int y) override { icon.setPosition(x, y); w.draw(icon); /* нужен текст a/b */ }
};

class FireballNode : public HitNode { public: FireballNode(const sf::Texture& t) : HitNode(t) {} };
class SwordNode : public AccumulativeNode { public: SwordNode(const sf::Texture& t) : AccumulativeNode(t, 5) {} };
class ChainNode : public AccumulativeNode { public: ChainNode(const sf::Texture& t) : AccumulativeNode(t, 3) {} };

class SkillTree
{
protected:
    std::shared_ptr<Node> root;
    int points;
public:
    SkillTree(int p) : points(p) {}
    virtual void build() = 0;
    std::shared_ptr<Node> getRoot() const { return root; }
    int getPoints() const { return points; }
    void spendPoint() { if (points > 0) --points; }
    void refundPoint() { ++points; }
};

class MageSkillTree : public SkillTree
{
public:
    MageSkillTree() : SkillTree(10) {}
    void build() override
    {
        // пример построения дерева
        sf::Texture t_fire, t_sword, t_chain;
        t_fire.loadFromFile("icon_fireball.png");
        t_sword.loadFromFile("icon_rect_sword.png");
        t_chain.loadFromFile("icon_rect_chain.png");
        auto fire = std::make_shared<FireballNode>(t_fire);
        auto sword = std::make_shared<SwordNode>(t_sword);
        auto chain = std::make_shared<ChainNode>(t_chain);
        fire->addChild(sword);
        fire->addChild(chain);
        fire->setState(State::Unblocked);
        root = fire;
    }
};

int main() { return 0; }