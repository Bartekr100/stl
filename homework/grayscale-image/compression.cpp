#include "compression.hpp"
#include "algorithm"

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

rawImage decompressGrayscale(const compressedImage& compressed) {
    rawImage decompressed{};
    auto decompress = [i = 0, j = 0, &decompressed](const std::pair<uint8_t, uint8_t>& pixel) mutable {
        if (i == width) {
            ++j;
            i = 0;
        }

        for (auto n = 0; n < pixel.second; ++n) {
            decompressed[j][i] = pixel.first;
            ++i;
        }
    };

    std::for_each(begin(compressed), end(compressed), decompress);
    return decompressed;
}