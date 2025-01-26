#include <arduinoFFT.h>


#include <arduinoFFT.h>
const uint16_t samples = 64; //This value MUST ALWAYS be a power of 2
const float signalFrequency = 1000;
const float samplingFrequency = 5000;
const uint8_t amplitude = 100;

float vReal[samples];
float vImag[samples];

ArduinoFFT<float> FFT = ArduinoFFT<float>(vReal, vImag, samples, samplingFrequency); /* Create FFT object */

void setup(){
    // Setup code
}

void loop() {
    // Get samples
    FFT.windowing(FFTWindow::Hamming, FFTDirection::Forward);  /* Weigh data */
    FFT.compute(FFTDirection::Forward); /* Compute FFT */
    FFT.complexToMagnitude(); /* Compute magnitudes */
    float x = FFT.majorPeak();
    // Rest of the code
}
