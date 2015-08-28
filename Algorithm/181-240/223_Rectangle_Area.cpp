#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
#include <math.h>
#include <inttypes.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int covered = getCovered(A, B, C, D, E, F, G, H);
		return (G - E)*(H - F) + (C - A)*(D - B) - covered;
	}

	int getCovered(int A, int B, int C, int D, int E, int F, int G, int H) {
		if (A >= G || C <= E) return 0;
		if (B >= H || D <= F) return 0;
		if (A == C || B == D || E == G || F == H) return 0;
		return (min(C, G) - max(A, E))*(min(D, H) - max(B, F));
	}
};