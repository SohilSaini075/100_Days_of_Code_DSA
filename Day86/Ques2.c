// Sqrt(x)


int mySqrt(int x) {
    if (x == 0 || x == 1) return x;

    long long low = 0, high = x, ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;

        if (square == x) return (int)mid;
        else if (square < x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return (int)ans;
}