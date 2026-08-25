#include <array>
#include <cstdint>
#include <vector>
#include <cstddef>

constexpr size_t width = 32;
constexpr size_t height = 32;

using compressedImage = std::vector<std::pair<uint8_t, uint8_t>>;
using rawImage = std::array<std::array<uint8_t, width>, height>;

compressedImage compressGrayscale(const rawImage&);
