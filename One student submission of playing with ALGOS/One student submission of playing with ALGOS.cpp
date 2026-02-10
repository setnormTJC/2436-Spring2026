#include <algorithm>
#include <iostream>
#include <cmath>

struct Vec2 { float x, y; };
struct Vec2i { int x, y; };

static int edgeFunction(const Vec2i& a, const Vec2i& b, const Vec2i& p) {
    return (p.x - a.x) * (b.y - a.y) - (p.y - a.y) * (b.x - a.x);
}

static Vec2i rotateAround(const Vec2& p, const Vec2& c, float r) {
    float s = std::sin(r);
    float co = std::cos(r);

    float px = p.x - c.x;
    float py = p.y - c.y;

    return { (int)std::lround((px * co - py * s + c.x)), (int)std::lround((px * s + py * co + c.y)) };
}

const int W = 80;
const int H = 24;
char fb[H][W];

int main() {
    // Base triangle
    Vec2 b0{ 20.f,  5.f };
    Vec2 b1{ 60.f,  8.f };
    Vec2 b2{ 35.f, 20.f };

    Vec2 center{
        (b0.x + b1.x + b2.x) / 3.0f,
        (b0.y + b1.y + b2.y) / 3.0f
    };

    float angle = 0.0f;

    while (true) {
        std::fill(&fb[0][0], &fb[0][0] + (W * H), ' ');

        Vec2i v0 = rotateAround(b0, center, angle);
        Vec2i v1 = rotateAround(b1, center, angle);
        Vec2i v2 = rotateAround(b2, center, angle);

        int minX = std::max(0, std::min(v0.x, std::min(v1.x, v2.x)));
        int maxX = std::min(W - 1, std::max(v0.x, std::max(v1.x, v2.x)));
        int minY = std::max(0, std::min(v0.y, std::min(v1.y, v2.y)));
        int maxY = std::min(H - 1, std::max(v0.y, std::max(v1.y, v2.y)));

        int area = edgeFunction(v0, v1, v2);
        bool isCCW = (area >= 0);

        auto inside = [&](int x, int y) {
            Vec2i p{ x, y };
            int w0 = edgeFunction(v1, v2, p);
            int w1 = edgeFunction(v2, v0, p);
            int w2 = edgeFunction(v0, v1, p);
            if (isCCW) return (w0 >= 0 && w1 >= 0 && w2 >= 0);
            return (w0 <= 0 && w1 <= 0 && w2 <= 0);
            };

        for (int y = minY; y <= maxY; ++y) {
            for (int x = minX; x <= maxX; ++x) {
                if (inside(x, y)) {
                    fb[y][x] = '*';
                }
            }
        }

        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x)
                std::cout << fb[y][x];
            std::cout << '\n';
        }
        std::cout << "\n\n\n Press enter for next frame";
        std::getchar();
        std::system("CLS");
        angle += 0.06f;
    }
}
