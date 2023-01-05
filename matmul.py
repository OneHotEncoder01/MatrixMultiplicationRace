# -*- coding: utf-8 -*-
"""
Created on Thu Jan  5 19:11:17 2023

@author: OneHotEncoder

"""

#Author Sinan ötük
import numpy as np
import time

N = 2048

A = np.random.randn(N,N).astype(np.float32)
B = np.random.randn(N,N).astype(np.float32)

flop = N*N*N*2
total = 0.0
for i in range(100):
    st = time.time()
    C = A @ B
    et = time.time()
    s = et - st 
    print(f"{(flop/s) * 1e-9:.2f} GFLOPS")