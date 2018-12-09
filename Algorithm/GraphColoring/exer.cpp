vcolor[1..n];
W[1..n][1..n];

fun(int level) {
	if (promising(level)) {
		if (level == n) {
			//cout;
		}
		else {
			for (int j = 1; j <= m; j++) {
				vcolor[level + 1] = j;
				fun(level + 1);
			}
		}
	}
	
}

bool promising(int level) {
	int k = 1;
	bool resFlag = true;
	while (k < level && resFlag) {
		if (vcolor[k] == vcolor[level] && W[level][k]) {
			resFlag = false;
		}
		k++;
	}
}