#include "eml_net.h"
static const float colorMLP_layer0_weights[15] = { 0.527698f, -1.193011f, -1.361947f, -1.331431f, -1.022025f, -0.440174f, -0.004628f, -0.032163f, 1.758070f, 1.389093f, -0.189395f, -1.315510f, -1.210177f, 0.509192f, 0.343505f };
static const float colorMLP_layer0_biases[5] = { -0.847890f, 0.047817f, -0.384393f, -0.816938f, 3.812384f };
static const float colorMLP_layer1_weights[30] = { -1.115949f, -0.172465f, 2.859235f, -0.472673f, -3.021096f, 3.219708f, -0.261509f, 0.124420f, -1.234451f, -0.026092f, 0.177914f, -0.391147f, 0.006472f, -0.577897f, -0.469671f, -0.299329f, -0.569868f, 0.473329f, -1.396556f, -2.418576f, 1.291556f, 2.897470f, 0.075873f, -0.915476f, 2.346932f, 3.205970f, -1.504037f, -3.819428f, 0.384698f, -0.339673f };
static const float colorMLP_layer1_biases[6] = { -4.479761f, 4.579941f, 4.380832f, 0.143713f, -1.653564f, -3.366723f };
static float colorMLP_buf1[6];
static float colorMLP_buf2[6];
static const EmlNetLayer colorMLP_layers[2] = { 
{ 5, 3, colorMLP_layer0_weights, colorMLP_layer0_biases, EmlNetActivationRelu }, 
{ 6, 5, colorMLP_layer1_weights, colorMLP_layer1_biases, EmlNetActivationSoftmax } };
static EmlNet colorMLP = { 2, colorMLP_layers, colorMLP_buf1, colorMLP_buf2, 6 };