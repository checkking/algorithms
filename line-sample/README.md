# line-sample

## line_sample.py
A script to sample file lines randomly

### Usage
```python
python line_sample.py file ratio
```
file: the file to sample
ratio: the ratio to sample, (0, 1)

## reservoir_sampling.c
An implementation of Reservoir sampling, you can use it to sample file lines

### Reservoir Sampling
**问题:** 如何随机从k个对象中选择一个对象，这n个对象是按序排列的，但是在此之前你是不知道n的值的。

**思路:** 先把读到的前k个对象放入“水库”，对于第k+1个对象开始，以k/(k+1)的概率选择该对象，以k/(k+2)的概率选择第k+2个对象，以此类推，以k/m的概率选择第m个对象（m>k）。如果m被选中，则随机替换水库中的一个对象。最终每个对象被选中的概率均为k/n.

**证明:**
第m个对象被选中的概率=选择m的概率*（其后元素不被选择的概率+其后元素被选择的概率*不替换第m个对象的概率），即:

P = k/m * [((m+1-k)/(m+1) + k/(m+1) * (k-1)/k) * ((m+2-k)/(m+2) + k/(m+2) * (k-1)/k) * ((n-k)/n + k/n * (k-1)/k)] = k/m * m/n = k/n
