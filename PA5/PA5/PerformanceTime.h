#ifndef PERFORMANCE_TIME_H
#define PERFORMANCE_TIME_H

#include <iostream>
#include <fstream>
#include "ChainingHash.h"
#include "ProbingHash.h"
#include "ParallelProbingHash.h"

void performanceTime(int maxNum);
void chainingPerformance(int maxNum);
void probingPerformance(int maxNum);
void parallelProbingPerformance(int maxNum);

#endif