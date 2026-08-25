#include "compression.hpp"

compressedImage compressGrayscale(const rawImage& image) {
    compressedImage compressed;
    compressed.reserve(image.size() * image[0].size());

    for (const auto& row : image) {
        uint8_t prevPixel = *row.begin();
        uint8_t n = 0;
        for (const auto& pixel : row) {
            if (pixel == prevPixel && n < 255) {
                ++n;
            }

            else {
                compressed.push_back({prevPixel, n});
                n = 1;
                prevPixel = pixel;
            }
        }
        compressed.push_back({prevPixel, n});
    }

    return compressed;
}