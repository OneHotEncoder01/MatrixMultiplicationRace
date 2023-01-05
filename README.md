# MatrixMultiplicationRace
Implementing c++ Matrix multiplicator that runs faster then python numpy libraries implementation


**speed is calculated with Flops**
  https://de.wikipedia.org/wiki/Floating_Point_Operations_Per_Second

**python requires numpy library to run**
  https://numpy.org/install/

N by N matrix requires N*N*N*2 flops to multiply

**Matmul.cpp**
  g++ Matmul.cpp -O2 && ./a.out

**python3**
  python3 matmul.py
