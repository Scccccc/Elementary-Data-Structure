#pragma once

typedef int HpDatatype;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void AdjustDown(HpDatatype* a, int n, int parent);
void Swap(HpDatatype* p1, HpDatatype* p2);