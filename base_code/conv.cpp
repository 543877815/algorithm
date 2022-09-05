#include <iostream>
#include <bits/stdc++.h>

void init(int *arr, int in_channel, int height, int width) {
    for (int i = 0; i < in_channel; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                *(arr + i * height * width + j * width + k) = 1;
            }
        }
    }
}

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int conv(const int *image, int *kernel, int idx_x, int idx_y, int channel, int height, int width, int stride, int kernel_size) {
    int res = 0;
    int shift = kernel_size / 2;
    int center_x = idx_x * stride, center_y = idx_y * stride;
    for (int i = 0; i < channel; i++) {
        for (int j = -shift; j <= shift; j++) {
            for (int k = -shift; k <= shift; k++) {
                int k_x = shift + j, k_y = shift + k;
                int img_x = center_x + j, img_y = center_y + k;
                if (isValid(img_x, img_y, height, width)) {
                    res += *(kernel + i * shift * shift + k_x * shift + k_y) * *(image + i * height * width + img_x * width + img_y);
                }
            }
        }
    }
    return res;
}

int main() {
    const int kernel_size = 3, stride = 2, padding = 1;
    const int in_channel = 3, in_height = 5, in_width = 5;
    const int out_channel = 3,
            out_height = (in_height + 2 * padding - kernel_size) / stride + 1,
            out_width = (in_width + 2 * padding - kernel_size) / stride + 1;
    const int num_kernel = out_channel;

    int in_image[in_channel][in_height][in_width];
    int kernel[num_kernel][in_channel][kernel_size][kernel_size];
    int out_image[out_channel][out_height][out_width];
    init((int *) in_image, in_channel, in_height, in_width);
    init((int *) kernel, in_channel, in_height, in_width);
    for (int i = 0; i < out_channel; i++) {
        for (int j = 0; j < out_height; j++) {
            for (int k = 0; k < out_width; k++) {
                out_image[i][j][k] = conv((int *) in_image,
                                          (int *) kernel[i],
                                          j,
                                          k,
                                          in_channel,
                                          in_height,
                                          in_width,
                                          stride,
                                          kernel_size);
                cout << out_image[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}