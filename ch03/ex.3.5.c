void decode1(long *xp, long *yp, long *zp) {
    long temp = *xp;
    *xp = *zp;
    *zp = *yp;
    *yp = temp;
}

void decode2(long *xp, long *yp, long *zp) {
    long x = *xp;
    long y = *yp;
    long z = *zp;

    *xp = z;
    *yp = x;
    *zp = y;
}