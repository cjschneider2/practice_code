# The Frequency

https://www.codeeval.com/open_challenges/168/

## Challenge Description

You are given 0.1 second short segments of signals of different shapes,
represented as sequences of integer numbers from -127 to 127. Sampling rate is
20,000 Hz (e.g., samples are taken with 1/20,000 sec time interval). The signal
may contain some slight noise. On the segment, the signal amplitude can
increase or decrease linearly, as well as the signal can move linearly up or
down relative to zero level: 

 Your task is to find the frequency of each signal.
 
### Input sample:

The first argument is a file with signals data, one signal per line.
Signal samples are space delimited.
For example:

    20 22 23 25 27 27 30 30 30 31 30 31 30 ... 49 53 55 56 61 62 64 67 68 72 74
(Some samples were skipped, you can download full example)

### Output sample:

Print to stdout the signal frequencies in Hz, one per line.
For example:
    310

## Constraints:

    1) Signal waveform can be sine, triangle, sawtooth, or square.

    2) Signal frequency is a multiple of 10 and is in the range
       from 150 Hz to 2000 Hz.

    3) Noise amplitude does not exceed 10 percent of the signal amplitude.

    4) Signal amplitude is not lower than 20.

    5) Signal amplitude change and the move relative to zero level on the
       segment are linear and do not change their direction.
