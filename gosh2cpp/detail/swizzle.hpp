#ifndef GOSH2CPP_SWIZZLE_H_INCLUDED
#define GOSH2CPP_SWIZZLE_H_INCLUDED

#define GOSH2CPP_INSERT_SWIZZLE_2             \
	detail::swizzle<vec, T, 2, 0, 0> xx;         \
	detail::swizzle<vec, T, 2, 0, 1> xy;         \
	detail::swizzle<vec, T, 2, 1, 0> yx;         \
	detail::swizzle<vec, T, 2, 1, 1> yy;         \
	detail::swizzle<vec, T, 2, 0, 0, 0> xxx;     \
	detail::swizzle<vec, T, 2, 0, 0, 1> xxy;     \
	detail::swizzle<vec, T, 2, 0, 1, 0> xyx;     \
	detail::swizzle<vec, T, 2, 0, 1, 1> xyy;     \
	detail::swizzle<vec, T, 2, 1, 0, 0> yxx;     \
	detail::swizzle<vec, T, 2, 1, 0, 1> yxy;     \
	detail::swizzle<vec, T, 2, 1, 1, 0> yyx;     \
	detail::swizzle<vec, T, 2, 1, 1, 1> yyy;     \
	detail::swizzle<vec, T, 2, 0, 0, 0, 0> xxxx; \
	detail::swizzle<vec, T, 2, 0, 0, 0, 1> xxxy; \
	detail::swizzle<vec, T, 2, 0, 0, 1, 0> xxyx; \
	detail::swizzle<vec, T, 2, 0, 0, 1, 1> xxyy; \
	detail::swizzle<vec, T, 2, 0, 1, 0, 0> xyxx; \
	detail::swizzle<vec, T, 2, 0, 1, 0, 1> xyxy; \
	detail::swizzle<vec, T, 2, 0, 1, 1, 0> xyyx; \
	detail::swizzle<vec, T, 2, 0, 1, 1, 1> xyyy; \
	detail::swizzle<vec, T, 2, 1, 0, 0, 0> yxxx; \
	detail::swizzle<vec, T, 2, 1, 0, 0, 1> yxxy; \
	detail::swizzle<vec, T, 2, 1, 0, 1, 0> yxyx; \
	detail::swizzle<vec, T, 2, 1, 0, 1, 1> yxyy; \
	detail::swizzle<vec, T, 2, 1, 1, 0, 0> yyxx; \
	detail::swizzle<vec, T, 2, 1, 1, 0, 1> yyxy; \
	detail::swizzle<vec, T, 2, 1, 1, 1, 0> yyyx; \
	detail::swizzle<vec, T, 2, 1, 1, 1, 1> yyyy;

#define GOSH2CPP_INSERT_SWIZZLE_3             \
	detail::swizzle<vec, T, 3, 0, 0> xx;         \
	detail::swizzle<vec, T, 3, 0, 1> xy;         \
	detail::swizzle<vec, T, 3, 0, 2> xz;         \
	detail::swizzle<vec, T, 3, 1, 0> yx;         \
	detail::swizzle<vec, T, 3, 1, 1> yy;         \
	detail::swizzle<vec, T, 3, 1, 2> yz;         \
	detail::swizzle<vec, T, 3, 2, 0> zx;         \
	detail::swizzle<vec, T, 3, 2, 1> zy;         \
	detail::swizzle<vec, T, 3, 2, 2> zz;         \
	detail::swizzle<vec, T, 3, 0, 0, 0> xxx;     \
	detail::swizzle<vec, T, 3, 0, 0, 1> xxy;     \
	detail::swizzle<vec, T, 3, 0, 0, 2> xxz;     \
	detail::swizzle<vec, T, 3, 0, 1, 0> xyx;     \
	detail::swizzle<vec, T, 3, 0, 1, 1> xyy;     \
	detail::swizzle<vec, T, 3, 0, 1, 2> xyz;     \
	detail::swizzle<vec, T, 3, 0, 2, 0> xzx;     \
	detail::swizzle<vec, T, 3, 0, 2, 1> xzy;     \
	detail::swizzle<vec, T, 3, 0, 2, 2> xzz;     \
	detail::swizzle<vec, T, 3, 1, 0, 0> yxx;     \
	detail::swizzle<vec, T, 3, 1, 0, 1> yxy;     \
	detail::swizzle<vec, T, 3, 1, 0, 2> yxz;     \
	detail::swizzle<vec, T, 3, 1, 1, 0> yyx;     \
	detail::swizzle<vec, T, 3, 1, 1, 1> yyy;     \
	detail::swizzle<vec, T, 3, 1, 1, 2> yyz;     \
	detail::swizzle<vec, T, 3, 1, 2, 0> yzx;     \
	detail::swizzle<vec, T, 3, 1, 2, 1> yzy;     \
	detail::swizzle<vec, T, 3, 1, 2, 2> yzz;     \
	detail::swizzle<vec, T, 3, 2, 0, 0> zxx;     \
	detail::swizzle<vec, T, 3, 2, 0, 1> zxy;     \
	detail::swizzle<vec, T, 3, 2, 0, 2> zxz;     \
	detail::swizzle<vec, T, 3, 2, 1, 0> zyx;     \
	detail::swizzle<vec, T, 3, 2, 1, 1> zyy;     \
	detail::swizzle<vec, T, 3, 2, 1, 2> zyz;     \
	detail::swizzle<vec, T, 3, 2, 2, 0> zzx;     \
	detail::swizzle<vec, T, 3, 2, 2, 1> zzy;     \
	detail::swizzle<vec, T, 3, 2, 2, 2> zzz;     \
	detail::swizzle<vec, T, 3, 0, 0, 0, 0> xxxx; \
	detail::swizzle<vec, T, 3, 0, 0, 0, 1> xxxy; \
	detail::swizzle<vec, T, 3, 0, 0, 0, 2> xxxz; \
	detail::swizzle<vec, T, 3, 0, 0, 1, 0> xxyx; \
	detail::swizzle<vec, T, 3, 0, 0, 1, 1> xxyy; \
	detail::swizzle<vec, T, 3, 0, 0, 1, 2> xxyz; \
	detail::swizzle<vec, T, 3, 0, 0, 2, 0> xxzx; \
	detail::swizzle<vec, T, 3, 0, 0, 2, 1> xxzy; \
	detail::swizzle<vec, T, 3, 0, 0, 2, 2> xxzz; \
	detail::swizzle<vec, T, 3, 0, 1, 0, 0> xyxx; \
	detail::swizzle<vec, T, 3, 0, 1, 0, 1> xyxy; \
	detail::swizzle<vec, T, 3, 0, 1, 0, 2> xyxz; \
	detail::swizzle<vec, T, 3, 0, 1, 1, 0> xyyx; \
	detail::swizzle<vec, T, 3, 0, 1, 1, 1> xyyy; \
	detail::swizzle<vec, T, 3, 0, 1, 1, 2> xyyz; \
	detail::swizzle<vec, T, 3, 0, 1, 2, 0> xyzx; \
	detail::swizzle<vec, T, 3, 0, 1, 2, 1> xyzy; \
	detail::swizzle<vec, T, 3, 0, 1, 2, 2> xyzz; \
	detail::swizzle<vec, T, 3, 0, 2, 0, 0> xzxx; \
	detail::swizzle<vec, T, 3, 0, 2, 0, 1> xzxy; \
	detail::swizzle<vec, T, 3, 0, 2, 0, 2> xzxz; \
	detail::swizzle<vec, T, 3, 0, 2, 1, 0> xzyx; \
	detail::swizzle<vec, T, 3, 0, 2, 1, 1> xzyy; \
	detail::swizzle<vec, T, 3, 0, 2, 1, 2> xzyz; \
	detail::swizzle<vec, T, 3, 0, 2, 2, 0> xzzx; \
	detail::swizzle<vec, T, 3, 0, 2, 2, 1> xzzy; \
	detail::swizzle<vec, T, 3, 0, 2, 2, 2> xzzz; \
	detail::swizzle<vec, T, 3, 1, 0, 0, 0> yxxx; \
	detail::swizzle<vec, T, 3, 1, 0, 0, 1> yxxy; \
	detail::swizzle<vec, T, 3, 1, 0, 0, 2> yxxz; \
	detail::swizzle<vec, T, 3, 1, 0, 1, 0> yxyx; \
	detail::swizzle<vec, T, 3, 1, 0, 1, 1> yxyy; \
	detail::swizzle<vec, T, 3, 1, 0, 1, 2> yxyz; \
	detail::swizzle<vec, T, 3, 1, 0, 2, 0> yxzx; \
	detail::swizzle<vec, T, 3, 1, 0, 2, 1> yxzy; \
	detail::swizzle<vec, T, 3, 1, 0, 2, 2> yxzz; \
	detail::swizzle<vec, T, 3, 1, 1, 0, 0> yyxx; \
	detail::swizzle<vec, T, 3, 1, 1, 0, 1> yyxy; \
	detail::swizzle<vec, T, 3, 1, 1, 0, 2> yyxz; \
	detail::swizzle<vec, T, 3, 1, 1, 1, 0> yyyx; \
	detail::swizzle<vec, T, 3, 1, 1, 1, 1> yyyy; \
	detail::swizzle<vec, T, 3, 1, 1, 1, 2> yyyz; \
	detail::swizzle<vec, T, 3, 1, 1, 2, 0> yyzx; \
	detail::swizzle<vec, T, 3, 1, 1, 2, 1> yyzy; \
	detail::swizzle<vec, T, 3, 1, 1, 2, 2> yyzz; \
	detail::swizzle<vec, T, 3, 1, 2, 0, 0> yzxx; \
	detail::swizzle<vec, T, 3, 1, 2, 0, 1> yzxy; \
	detail::swizzle<vec, T, 3, 1, 2, 0, 2> yzxz; \
	detail::swizzle<vec, T, 3, 1, 2, 1, 0> yzyx; \
	detail::swizzle<vec, T, 3, 1, 2, 1, 1> yzyy; \
	detail::swizzle<vec, T, 3, 1, 2, 1, 2> yzyz; \
	detail::swizzle<vec, T, 3, 1, 2, 2, 0> yzzx; \
	detail::swizzle<vec, T, 3, 1, 2, 2, 1> yzzy; \
	detail::swizzle<vec, T, 3, 1, 2, 2, 2> yzzz; \
	detail::swizzle<vec, T, 3, 2, 0, 0, 0> zxxx; \
	detail::swizzle<vec, T, 3, 2, 0, 0, 1> zxxy; \
	detail::swizzle<vec, T, 3, 2, 0, 0, 2> zxxz; \
	detail::swizzle<vec, T, 3, 2, 0, 1, 0> zxyx; \
	detail::swizzle<vec, T, 3, 2, 0, 1, 1> zxyy; \
	detail::swizzle<vec, T, 3, 2, 0, 1, 2> zxyz; \
	detail::swizzle<vec, T, 3, 2, 0, 2, 0> zxzx; \
	detail::swizzle<vec, T, 3, 2, 0, 2, 1> zxzy; \
	detail::swizzle<vec, T, 3, 2, 0, 2, 2> zxzz; \
	detail::swizzle<vec, T, 3, 2, 1, 0, 0> zyxx; \
	detail::swizzle<vec, T, 3, 2, 1, 0, 1> zyxy; \
	detail::swizzle<vec, T, 3, 2, 1, 0, 2> zyxz; \
	detail::swizzle<vec, T, 3, 2, 1, 1, 0> zyyx; \
	detail::swizzle<vec, T, 3, 2, 1, 1, 1> zyyy; \
	detail::swizzle<vec, T, 3, 2, 1, 1, 2> zyyz; \
	detail::swizzle<vec, T, 3, 2, 1, 2, 0> zyzx; \
	detail::swizzle<vec, T, 3, 2, 1, 2, 1> zyzy; \
	detail::swizzle<vec, T, 3, 2, 1, 2, 2> zyzz; \
	detail::swizzle<vec, T, 3, 2, 2, 0, 0> zzxx; \
	detail::swizzle<vec, T, 3, 2, 2, 0, 1> zzxy; \
	detail::swizzle<vec, T, 3, 2, 2, 0, 2> zzxz; \
	detail::swizzle<vec, T, 3, 2, 2, 1, 0> zzyx; \
	detail::swizzle<vec, T, 3, 2, 2, 1, 1> zzyy; \
	detail::swizzle<vec, T, 3, 2, 2, 1, 2> zzyz; \
	detail::swizzle<vec, T, 3, 2, 2, 2, 0> zzzx; \
	detail::swizzle<vec, T, 3, 2, 2, 2, 1> zzzy; \
	detail::swizzle<vec, T, 3, 2, 2, 2, 2> zzzz; \
	detail::swizzle<vec, T, 3, 0, 0> rr;         \
	detail::swizzle<vec, T, 3, 0, 1> rg;         \
	detail::swizzle<vec, T, 3, 0, 2> rb;         \
	detail::swizzle<vec, T, 3, 1, 0> gr;         \
	detail::swizzle<vec, T, 3, 1, 1> gg;         \
	detail::swizzle<vec, T, 3, 1, 2> gb;         \
	detail::swizzle<vec, T, 3, 2, 0> br;         \
	detail::swizzle<vec, T, 3, 2, 1> bg;         \
	detail::swizzle<vec, T, 3, 2, 2> bb;         \
	detail::swizzle<vec, T, 3, 0, 0, 0> rrr;     \
	detail::swizzle<vec, T, 3, 0, 0, 1> rrg;     \
	detail::swizzle<vec, T, 3, 0, 0, 2> rrb;     \
	detail::swizzle<vec, T, 3, 0, 1, 0> rgr;     \
	detail::swizzle<vec, T, 3, 0, 1, 1> rgg;     \
	detail::swizzle<vec, T, 3, 0, 1, 2> rgb;     \
	detail::swizzle<vec, T, 3, 0, 2, 0> rbr;     \
	detail::swizzle<vec, T, 3, 0, 2, 1> rbg;     \
	detail::swizzle<vec, T, 3, 0, 2, 2> rbb;     \
	detail::swizzle<vec, T, 3, 1, 0, 0> grr;     \
	detail::swizzle<vec, T, 3, 1, 0, 1> grg;     \
	detail::swizzle<vec, T, 3, 1, 0, 2> grb;     \
	detail::swizzle<vec, T, 3, 1, 1, 0> ggr;     \
	detail::swizzle<vec, T, 3, 1, 1, 1> ggg;     \
	detail::swizzle<vec, T, 3, 1, 1, 2> ggb;     \
	detail::swizzle<vec, T, 3, 1, 2, 0> gbr;     \
	detail::swizzle<vec, T, 3, 1, 2, 1> gbg;     \
	detail::swizzle<vec, T, 3, 1, 2, 2> gbb;     \
	detail::swizzle<vec, T, 3, 2, 0, 0> brr;     \
	detail::swizzle<vec, T, 3, 2, 0, 1> brg;     \
	detail::swizzle<vec, T, 3, 2, 0, 2> brb;     \
	detail::swizzle<vec, T, 3, 2, 1, 0> bgr;     \
	detail::swizzle<vec, T, 3, 2, 1, 1> bgg;     \
	detail::swizzle<vec, T, 3, 2, 1, 2> bgb;     \
	detail::swizzle<vec, T, 3, 2, 2, 0> bbr;     \
	detail::swizzle<vec, T, 3, 2, 2, 1> bbg;     \
	detail::swizzle<vec, T, 3, 2, 2, 2> bbb;     \
	detail::swizzle<vec, T, 3, 0, 0, 0, 0> rrrr; \
	detail::swizzle<vec, T, 3, 0, 0, 0, 1> rrrg; \
	detail::swizzle<vec, T, 3, 0, 0, 0, 2> rrrb; \
	detail::swizzle<vec, T, 3, 0, 0, 1, 0> rrgr; \
	detail::swizzle<vec, T, 3, 0, 0, 1, 1> rrgg; \
	detail::swizzle<vec, T, 3, 0, 0, 1, 2> rrgb; \
	detail::swizzle<vec, T, 3, 0, 0, 2, 0> rrbr; \
	detail::swizzle<vec, T, 3, 0, 0, 2, 1> rrbg; \
	detail::swizzle<vec, T, 3, 0, 0, 2, 2> rrbb; \
	detail::swizzle<vec, T, 3, 0, 1, 0, 0> rgrr; \
	detail::swizzle<vec, T, 3, 0, 1, 0, 1> rgrg; \
	detail::swizzle<vec, T, 3, 0, 1, 0, 2> rgrb; \
	detail::swizzle<vec, T, 3, 0, 1, 1, 0> rggr; \
	detail::swizzle<vec, T, 3, 0, 1, 1, 1> rggg; \
	detail::swizzle<vec, T, 3, 0, 1, 1, 2> rggb; \
	detail::swizzle<vec, T, 3, 0, 1, 2, 0> rgbr; \
	detail::swizzle<vec, T, 3, 0, 1, 2, 1> rgbg; \
	detail::swizzle<vec, T, 3, 0, 1, 2, 2> rgbb; \
	detail::swizzle<vec, T, 3, 0, 2, 0, 0> rbrr; \
	detail::swizzle<vec, T, 3, 0, 2, 0, 1> rbrg; \
	detail::swizzle<vec, T, 3, 0, 2, 0, 2> rbrb; \
	detail::swizzle<vec, T, 3, 0, 2, 1, 0> rbgr; \
	detail::swizzle<vec, T, 3, 0, 2, 1, 1> rbgg; \
	detail::swizzle<vec, T, 3, 0, 2, 1, 2> rbgb; \
	detail::swizzle<vec, T, 3, 0, 2, 2, 0> rbbr; \
	detail::swizzle<vec, T, 3, 0, 2, 2, 1> rbbg; \
	detail::swizzle<vec, T, 3, 0, 2, 2, 2> rbbb; \
	detail::swizzle<vec, T, 3, 1, 0, 0, 0> grrr; \
	detail::swizzle<vec, T, 3, 1, 0, 0, 1> grrg; \
	detail::swizzle<vec, T, 3, 1, 0, 0, 2> grrb; \
	detail::swizzle<vec, T, 3, 1, 0, 1, 0> grgr; \
	detail::swizzle<vec, T, 3, 1, 0, 1, 1> grgg; \
	detail::swizzle<vec, T, 3, 1, 0, 1, 2> grgb; \
	detail::swizzle<vec, T, 3, 1, 0, 2, 0> grbr; \
	detail::swizzle<vec, T, 3, 1, 0, 2, 1> grbg; \
	detail::swizzle<vec, T, 3, 1, 0, 2, 2> grbb; \
	detail::swizzle<vec, T, 3, 1, 1, 0, 0> ggrr; \
	detail::swizzle<vec, T, 3, 1, 1, 0, 1> ggrg; \
	detail::swizzle<vec, T, 3, 1, 1, 0, 2> ggrb; \
	detail::swizzle<vec, T, 3, 1, 1, 1, 0> gggr; \
	detail::swizzle<vec, T, 3, 1, 1, 1, 1> gggg; \
	detail::swizzle<vec, T, 3, 1, 1, 1, 2> gggb; \
	detail::swizzle<vec, T, 3, 1, 1, 2, 0> ggbr; \
	detail::swizzle<vec, T, 3, 1, 1, 2, 1> ggbg; \
	detail::swizzle<vec, T, 3, 1, 1, 2, 2> ggbb; \
	detail::swizzle<vec, T, 3, 1, 2, 0, 0> gbrr; \
	detail::swizzle<vec, T, 3, 1, 2, 0, 1> gbrg; \
	detail::swizzle<vec, T, 3, 1, 2, 0, 2> gbrb; \
	detail::swizzle<vec, T, 3, 1, 2, 1, 0> gbgr; \
	detail::swizzle<vec, T, 3, 1, 2, 1, 1> gbgg; \
	detail::swizzle<vec, T, 3, 1, 2, 1, 2> gbgb; \
	detail::swizzle<vec, T, 3, 1, 2, 2, 0> gbbr; \
	detail::swizzle<vec, T, 3, 1, 2, 2, 1> gbbg; \
	detail::swizzle<vec, T, 3, 1, 2, 2, 2> gbbb; \
	detail::swizzle<vec, T, 3, 2, 0, 0, 0> brrr; \
	detail::swizzle<vec, T, 3, 2, 0, 0, 1> brrg; \
	detail::swizzle<vec, T, 3, 2, 0, 0, 2> brrb; \
	detail::swizzle<vec, T, 3, 2, 0, 1, 0> brgr; \
	detail::swizzle<vec, T, 3, 2, 0, 1, 1> brgg; \
	detail::swizzle<vec, T, 3, 2, 0, 1, 2> brgb; \
	detail::swizzle<vec, T, 3, 2, 0, 2, 0> brbr; \
	detail::swizzle<vec, T, 3, 2, 0, 2, 1> brbg; \
	detail::swizzle<vec, T, 3, 2, 0, 2, 2> brbb; \
	detail::swizzle<vec, T, 3, 2, 1, 0, 0> bgrr; \
	detail::swizzle<vec, T, 3, 2, 1, 0, 1> bgrg; \
	detail::swizzle<vec, T, 3, 2, 1, 0, 2> bgrb; \
	detail::swizzle<vec, T, 3, 2, 1, 1, 0> bggr; \
	detail::swizzle<vec, T, 3, 2, 1, 1, 1> bggg; \
	detail::swizzle<vec, T, 3, 2, 1, 1, 2> bggb; \
	detail::swizzle<vec, T, 3, 2, 1, 2, 0> bgbr; \
	detail::swizzle<vec, T, 3, 2, 1, 2, 1> bgbg; \
	detail::swizzle<vec, T, 3, 2, 1, 2, 2> bgbb; \
	detail::swizzle<vec, T, 3, 2, 2, 0, 0> bbrr; \
	detail::swizzle<vec, T, 3, 2, 2, 0, 1> bbrg; \
	detail::swizzle<vec, T, 3, 2, 2, 0, 2> bbrb; \
	detail::swizzle<vec, T, 3, 2, 2, 1, 0> bbgr; \
	detail::swizzle<vec, T, 3, 2, 2, 1, 1> bbgg; \
	detail::swizzle<vec, T, 3, 2, 2, 1, 2> bbgb; \
	detail::swizzle<vec, T, 3, 2, 2, 2, 0> bbbr; \
	detail::swizzle<vec, T, 3, 2, 2, 2, 1> bbbg; \
	detail::swizzle<vec, T, 3, 2, 2, 2, 2> bbbb;

#define GOSH2CPP_INSERT_SWIZZLE_4             \
	detail::swizzle<vec, T, 4, 0, 0> xx;         \
	detail::swizzle<vec, T, 4, 0, 1> xy;         \
	detail::swizzle<vec, T, 4, 0, 2> xz;         \
	detail::swizzle<vec, T, 4, 0, 3> xw;         \
	detail::swizzle<vec, T, 4, 1, 0> yx;         \
	detail::swizzle<vec, T, 4, 1, 1> yy;         \
	detail::swizzle<vec, T, 4, 1, 2> yz;         \
	detail::swizzle<vec, T, 4, 1, 3> yw;         \
	detail::swizzle<vec, T, 4, 2, 0> zx;         \
	detail::swizzle<vec, T, 4, 2, 1> zy;         \
	detail::swizzle<vec, T, 4, 2, 2> zz;         \
	detail::swizzle<vec, T, 4, 2, 3> zw;         \
	detail::swizzle<vec, T, 4, 3, 0> wx;         \
	detail::swizzle<vec, T, 4, 3, 1> wy;         \
	detail::swizzle<vec, T, 4, 3, 2> wz;         \
	detail::swizzle<vec, T, 4, 3, 3> ww;         \
	detail::swizzle<vec, T, 4, 0, 0, 0> xxx;     \
	detail::swizzle<vec, T, 4, 0, 0, 1> xxy;     \
	detail::swizzle<vec, T, 4, 0, 0, 2> xxz;     \
	detail::swizzle<vec, T, 4, 0, 0, 3> xxw;     \
	detail::swizzle<vec, T, 4, 0, 1, 0> xyx;     \
	detail::swizzle<vec, T, 4, 0, 1, 1> xyy;     \
	detail::swizzle<vec, T, 4, 0, 1, 2> xyz;     \
	detail::swizzle<vec, T, 4, 0, 1, 3> xyw;     \
	detail::swizzle<vec, T, 4, 0, 2, 0> xzx;     \
	detail::swizzle<vec, T, 4, 0, 2, 1> xzy;     \
	detail::swizzle<vec, T, 4, 0, 2, 2> xzz;     \
	detail::swizzle<vec, T, 4, 0, 2, 3> xzw;     \
	detail::swizzle<vec, T, 4, 0, 3, 0> xwx;     \
	detail::swizzle<vec, T, 4, 0, 3, 1> xwy;     \
	detail::swizzle<vec, T, 4, 0, 3, 2> xwz;     \
	detail::swizzle<vec, T, 4, 0, 3, 3> xww;     \
	detail::swizzle<vec, T, 4, 1, 0, 0> yxx;     \
	detail::swizzle<vec, T, 4, 1, 0, 1> yxy;     \
	detail::swizzle<vec, T, 4, 1, 0, 2> yxz;     \
	detail::swizzle<vec, T, 4, 1, 0, 3> yxw;     \
	detail::swizzle<vec, T, 4, 1, 1, 0> yyx;     \
	detail::swizzle<vec, T, 4, 1, 1, 1> yyy;     \
	detail::swizzle<vec, T, 4, 1, 1, 2> yyz;     \
	detail::swizzle<vec, T, 4, 1, 1, 3> yyw;     \
	detail::swizzle<vec, T, 4, 1, 2, 0> yzx;     \
	detail::swizzle<vec, T, 4, 1, 2, 1> yzy;     \
	detail::swizzle<vec, T, 4, 1, 2, 2> yzz;     \
	detail::swizzle<vec, T, 4, 1, 2, 3> yzw;     \
	detail::swizzle<vec, T, 4, 1, 3, 0> ywx;     \
	detail::swizzle<vec, T, 4, 1, 3, 1> ywy;     \
	detail::swizzle<vec, T, 4, 1, 3, 2> ywz;     \
	detail::swizzle<vec, T, 4, 1, 3, 3> yww;     \
	detail::swizzle<vec, T, 4, 2, 0, 0> zxx;     \
	detail::swizzle<vec, T, 4, 2, 0, 1> zxy;     \
	detail::swizzle<vec, T, 4, 2, 0, 2> zxz;     \
	detail::swizzle<vec, T, 4, 2, 0, 3> zxw;     \
	detail::swizzle<vec, T, 4, 2, 1, 0> zyx;     \
	detail::swizzle<vec, T, 4, 2, 1, 1> zyy;     \
	detail::swizzle<vec, T, 4, 2, 1, 2> zyz;     \
	detail::swizzle<vec, T, 4, 2, 1, 3> zyw;     \
	detail::swizzle<vec, T, 4, 2, 2, 0> zzx;     \
	detail::swizzle<vec, T, 4, 2, 2, 1> zzy;     \
	detail::swizzle<vec, T, 4, 2, 2, 2> zzz;     \
	detail::swizzle<vec, T, 4, 2, 2, 3> zzw;     \
	detail::swizzle<vec, T, 4, 2, 3, 0> zwx;     \
	detail::swizzle<vec, T, 4, 2, 3, 1> zwy;     \
	detail::swizzle<vec, T, 4, 2, 3, 2> zwz;     \
	detail::swizzle<vec, T, 4, 2, 3, 3> zww;     \
	detail::swizzle<vec, T, 4, 3, 0, 0> wxx;     \
	detail::swizzle<vec, T, 4, 3, 0, 1> wxy;     \
	detail::swizzle<vec, T, 4, 3, 0, 2> wxz;     \
	detail::swizzle<vec, T, 4, 3, 0, 3> wxw;     \
	detail::swizzle<vec, T, 4, 3, 1, 0> wyx;     \
	detail::swizzle<vec, T, 4, 3, 1, 1> wyy;     \
	detail::swizzle<vec, T, 4, 3, 1, 2> wyz;     \
	detail::swizzle<vec, T, 4, 3, 1, 3> wyw;     \
	detail::swizzle<vec, T, 4, 3, 2, 0> wzx;     \
	detail::swizzle<vec, T, 4, 3, 2, 1> wzy;     \
	detail::swizzle<vec, T, 4, 3, 2, 2> wzz;     \
	detail::swizzle<vec, T, 4, 3, 2, 3> wzw;     \
	detail::swizzle<vec, T, 4, 3, 3, 0> wwx;     \
	detail::swizzle<vec, T, 4, 3, 3, 1> wwy;     \
	detail::swizzle<vec, T, 4, 3, 3, 2> wwz;     \
	detail::swizzle<vec, T, 4, 3, 3, 3> www;     \
	detail::swizzle<vec, T, 4, 0, 0, 0, 0> xxxx; \
	detail::swizzle<vec, T, 4, 0, 0, 0, 1> xxxy; \
	detail::swizzle<vec, T, 4, 0, 0, 0, 2> xxxz; \
	detail::swizzle<vec, T, 4, 0, 0, 0, 3> xxxw; \
	detail::swizzle<vec, T, 4, 0, 0, 1, 0> xxyx; \
	detail::swizzle<vec, T, 4, 0, 0, 1, 1> xxyy; \
	detail::swizzle<vec, T, 4, 0, 0, 1, 2> xxyz; \
	detail::swizzle<vec, T, 4, 0, 0, 1, 3> xxyw; \
	detail::swizzle<vec, T, 4, 0, 0, 2, 0> xxzx; \
	detail::swizzle<vec, T, 4, 0, 0, 2, 1> xxzy; \
	detail::swizzle<vec, T, 4, 0, 0, 2, 2> xxzz; \
	detail::swizzle<vec, T, 4, 0, 0, 2, 3> xxzw; \
	detail::swizzle<vec, T, 4, 0, 0, 3, 0> xxwx; \
	detail::swizzle<vec, T, 4, 0, 0, 3, 1> xxwy; \
	detail::swizzle<vec, T, 4, 0, 0, 3, 2> xxwz; \
	detail::swizzle<vec, T, 4, 0, 0, 3, 3> xxww; \
	detail::swizzle<vec, T, 4, 0, 1, 0, 0> xyxx; \
	detail::swizzle<vec, T, 4, 0, 1, 0, 1> xyxy; \
	detail::swizzle<vec, T, 4, 0, 1, 0, 2> xyxz; \
	detail::swizzle<vec, T, 4, 0, 1, 0, 3> xyxw; \
	detail::swizzle<vec, T, 4, 0, 1, 1, 0> xyyx; \
	detail::swizzle<vec, T, 4, 0, 1, 1, 1> xyyy; \
	detail::swizzle<vec, T, 4, 0, 1, 1, 2> xyyz; \
	detail::swizzle<vec, T, 4, 0, 1, 1, 3> xyyw; \
	detail::swizzle<vec, T, 4, 0, 1, 2, 0> xyzx; \
	detail::swizzle<vec, T, 4, 0, 1, 2, 1> xyzy; \
	detail::swizzle<vec, T, 4, 0, 1, 2, 2> xyzz; \
	detail::swizzle<vec, T, 4, 0, 1, 2, 3> xyzw; \
	detail::swizzle<vec, T, 4, 0, 1, 3, 0> xywx; \
	detail::swizzle<vec, T, 4, 0, 1, 3, 1> xywy; \
	detail::swizzle<vec, T, 4, 0, 1, 3, 2> xywz; \
	detail::swizzle<vec, T, 4, 0, 1, 3, 3> xyww; \
	detail::swizzle<vec, T, 4, 0, 2, 0, 0> xzxx; \
	detail::swizzle<vec, T, 4, 0, 2, 0, 1> xzxy; \
	detail::swizzle<vec, T, 4, 0, 2, 0, 2> xzxz; \
	detail::swizzle<vec, T, 4, 0, 2, 0, 3> xzxw; \
	detail::swizzle<vec, T, 4, 0, 2, 1, 0> xzyx; \
	detail::swizzle<vec, T, 4, 0, 2, 1, 1> xzyy; \
	detail::swizzle<vec, T, 4, 0, 2, 1, 2> xzyz; \
	detail::swizzle<vec, T, 4, 0, 2, 1, 3> xzyw; \
	detail::swizzle<vec, T, 4, 0, 2, 2, 0> xzzx; \
	detail::swizzle<vec, T, 4, 0, 2, 2, 1> xzzy; \
	detail::swizzle<vec, T, 4, 0, 2, 2, 2> xzzz; \
	detail::swizzle<vec, T, 4, 0, 2, 2, 3> xzzw; \
	detail::swizzle<vec, T, 4, 0, 2, 3, 0> xzwx; \
	detail::swizzle<vec, T, 4, 0, 2, 3, 1> xzwy; \
	detail::swizzle<vec, T, 4, 0, 2, 3, 2> xzwz; \
	detail::swizzle<vec, T, 4, 0, 2, 3, 3> xzww; \
	detail::swizzle<vec, T, 4, 0, 3, 0, 0> xwxx; \
	detail::swizzle<vec, T, 4, 0, 3, 0, 1> xwxy; \
	detail::swizzle<vec, T, 4, 0, 3, 0, 2> xwxz; \
	detail::swizzle<vec, T, 4, 0, 3, 0, 3> xwxw; \
	detail::swizzle<vec, T, 4, 0, 3, 1, 0> xwyx; \
	detail::swizzle<vec, T, 4, 0, 3, 1, 1> xwyy; \
	detail::swizzle<vec, T, 4, 0, 3, 1, 2> xwyz; \
	detail::swizzle<vec, T, 4, 0, 3, 1, 3> xwyw; \
	detail::swizzle<vec, T, 4, 0, 3, 2, 0> xwzx; \
	detail::swizzle<vec, T, 4, 0, 3, 2, 1> xwzy; \
	detail::swizzle<vec, T, 4, 0, 3, 2, 2> xwzz; \
	detail::swizzle<vec, T, 4, 0, 3, 2, 3> xwzw; \
	detail::swizzle<vec, T, 4, 0, 3, 3, 0> xwwx; \
	detail::swizzle<vec, T, 4, 0, 3, 3, 1> xwwy; \
	detail::swizzle<vec, T, 4, 0, 3, 3, 2> xwwz; \
	detail::swizzle<vec, T, 4, 0, 3, 3, 3> xwww; \
	detail::swizzle<vec, T, 4, 1, 0, 0, 0> yxxx; \
	detail::swizzle<vec, T, 4, 1, 0, 0, 1> yxxy; \
	detail::swizzle<vec, T, 4, 1, 0, 0, 2> yxxz; \
	detail::swizzle<vec, T, 4, 1, 0, 0, 3> yxxw; \
	detail::swizzle<vec, T, 4, 1, 0, 1, 0> yxyx; \
	detail::swizzle<vec, T, 4, 1, 0, 1, 1> yxyy; \
	detail::swizzle<vec, T, 4, 1, 0, 1, 2> yxyz; \
	detail::swizzle<vec, T, 4, 1, 0, 1, 3> yxyw; \
	detail::swizzle<vec, T, 4, 1, 0, 2, 0> yxzx; \
	detail::swizzle<vec, T, 4, 1, 0, 2, 1> yxzy; \
	detail::swizzle<vec, T, 4, 1, 0, 2, 2> yxzz; \
	detail::swizzle<vec, T, 4, 1, 0, 2, 3> yxzw; \
	detail::swizzle<vec, T, 4, 1, 0, 3, 0> yxwx; \
	detail::swizzle<vec, T, 4, 1, 0, 3, 1> yxwy; \
	detail::swizzle<vec, T, 4, 1, 0, 3, 2> yxwz; \
	detail::swizzle<vec, T, 4, 1, 0, 3, 3> yxww; \
	detail::swizzle<vec, T, 4, 1, 1, 0, 0> yyxx; \
	detail::swizzle<vec, T, 4, 1, 1, 0, 1> yyxy; \
	detail::swizzle<vec, T, 4, 1, 1, 0, 2> yyxz; \
	detail::swizzle<vec, T, 4, 1, 1, 0, 3> yyxw; \
	detail::swizzle<vec, T, 4, 1, 1, 1, 0> yyyx; \
	detail::swizzle<vec, T, 4, 1, 1, 1, 1> yyyy; \
	detail::swizzle<vec, T, 4, 1, 1, 1, 2> yyyz; \
	detail::swizzle<vec, T, 4, 1, 1, 1, 3> yyyw; \
	detail::swizzle<vec, T, 4, 1, 1, 2, 0> yyzx; \
	detail::swizzle<vec, T, 4, 1, 1, 2, 1> yyzy; \
	detail::swizzle<vec, T, 4, 1, 1, 2, 2> yyzz; \
	detail::swizzle<vec, T, 4, 1, 1, 2, 3> yyzw; \
	detail::swizzle<vec, T, 4, 1, 1, 3, 0> yywx; \
	detail::swizzle<vec, T, 4, 1, 1, 3, 1> yywy; \
	detail::swizzle<vec, T, 4, 1, 1, 3, 2> yywz; \
	detail::swizzle<vec, T, 4, 1, 1, 3, 3> yyww; \
	detail::swizzle<vec, T, 4, 1, 2, 0, 0> yzxx; \
	detail::swizzle<vec, T, 4, 1, 2, 0, 1> yzxy; \
	detail::swizzle<vec, T, 4, 1, 2, 0, 2> yzxz; \
	detail::swizzle<vec, T, 4, 1, 2, 0, 3> yzxw; \
	detail::swizzle<vec, T, 4, 1, 2, 1, 0> yzyx; \
	detail::swizzle<vec, T, 4, 1, 2, 1, 1> yzyy; \
	detail::swizzle<vec, T, 4, 1, 2, 1, 2> yzyz; \
	detail::swizzle<vec, T, 4, 1, 2, 1, 3> yzyw; \
	detail::swizzle<vec, T, 4, 1, 2, 2, 0> yzzx; \
	detail::swizzle<vec, T, 4, 1, 2, 2, 1> yzzy; \
	detail::swizzle<vec, T, 4, 1, 2, 2, 2> yzzz; \
	detail::swizzle<vec, T, 4, 1, 2, 2, 3> yzzw; \
	detail::swizzle<vec, T, 4, 1, 2, 3, 0> yzwx; \
	detail::swizzle<vec, T, 4, 1, 2, 3, 1> yzwy; \
	detail::swizzle<vec, T, 4, 1, 2, 3, 2> yzwz; \
	detail::swizzle<vec, T, 4, 1, 2, 3, 3> yzww; \
	detail::swizzle<vec, T, 4, 1, 3, 0, 0> ywxx; \
	detail::swizzle<vec, T, 4, 1, 3, 0, 1> ywxy; \
	detail::swizzle<vec, T, 4, 1, 3, 0, 2> ywxz; \
	detail::swizzle<vec, T, 4, 1, 3, 0, 3> ywxw; \
	detail::swizzle<vec, T, 4, 1, 3, 1, 0> ywyx; \
	detail::swizzle<vec, T, 4, 1, 3, 1, 1> ywyy; \
	detail::swizzle<vec, T, 4, 1, 3, 1, 2> ywyz; \
	detail::swizzle<vec, T, 4, 1, 3, 1, 3> ywyw; \
	detail::swizzle<vec, T, 4, 1, 3, 2, 0> ywzx; \
	detail::swizzle<vec, T, 4, 1, 3, 2, 1> ywzy; \
	detail::swizzle<vec, T, 4, 1, 3, 2, 2> ywzz; \
	detail::swizzle<vec, T, 4, 1, 3, 2, 3> ywzw; \
	detail::swizzle<vec, T, 4, 1, 3, 3, 0> ywwx; \
	detail::swizzle<vec, T, 4, 1, 3, 3, 1> ywwy; \
	detail::swizzle<vec, T, 4, 1, 3, 3, 2> ywwz; \
	detail::swizzle<vec, T, 4, 1, 3, 3, 3> ywww; \
	detail::swizzle<vec, T, 4, 2, 0, 0, 0> zxxx; \
	detail::swizzle<vec, T, 4, 2, 0, 0, 1> zxxy; \
	detail::swizzle<vec, T, 4, 2, 0, 0, 2> zxxz; \
	detail::swizzle<vec, T, 4, 2, 0, 0, 3> zxxw; \
	detail::swizzle<vec, T, 4, 2, 0, 1, 0> zxyx; \
	detail::swizzle<vec, T, 4, 2, 0, 1, 1> zxyy; \
	detail::swizzle<vec, T, 4, 2, 0, 1, 2> zxyz; \
	detail::swizzle<vec, T, 4, 2, 0, 1, 3> zxyw; \
	detail::swizzle<vec, T, 4, 2, 0, 2, 0> zxzx; \
	detail::swizzle<vec, T, 4, 2, 0, 2, 1> zxzy; \
	detail::swizzle<vec, T, 4, 2, 0, 2, 2> zxzz; \
	detail::swizzle<vec, T, 4, 2, 0, 2, 3> zxzw; \
	detail::swizzle<vec, T, 4, 2, 0, 3, 0> zxwx; \
	detail::swizzle<vec, T, 4, 2, 0, 3, 1> zxwy; \
	detail::swizzle<vec, T, 4, 2, 0, 3, 2> zxwz; \
	detail::swizzle<vec, T, 4, 2, 0, 3, 3> zxww; \
	detail::swizzle<vec, T, 4, 2, 1, 0, 0> zyxx; \
	detail::swizzle<vec, T, 4, 2, 1, 0, 1> zyxy; \
	detail::swizzle<vec, T, 4, 2, 1, 0, 2> zyxz; \
	detail::swizzle<vec, T, 4, 2, 1, 0, 3> zyxw; \
	detail::swizzle<vec, T, 4, 2, 1, 1, 0> zyyx; \
	detail::swizzle<vec, T, 4, 2, 1, 1, 1> zyyy; \
	detail::swizzle<vec, T, 4, 2, 1, 1, 2> zyyz; \
	detail::swizzle<vec, T, 4, 2, 1, 1, 3> zyyw; \
	detail::swizzle<vec, T, 4, 2, 1, 2, 0> zyzx; \
	detail::swizzle<vec, T, 4, 2, 1, 2, 1> zyzy; \
	detail::swizzle<vec, T, 4, 2, 1, 2, 2> zyzz; \
	detail::swizzle<vec, T, 4, 2, 1, 2, 3> zyzw; \
	detail::swizzle<vec, T, 4, 2, 1, 3, 0> zywx; \
	detail::swizzle<vec, T, 4, 2, 1, 3, 1> zywy; \
	detail::swizzle<vec, T, 4, 2, 1, 3, 2> zywz; \
	detail::swizzle<vec, T, 4, 2, 1, 3, 3> zyww; \
	detail::swizzle<vec, T, 4, 2, 2, 0, 0> zzxx; \
	detail::swizzle<vec, T, 4, 2, 2, 0, 1> zzxy; \
	detail::swizzle<vec, T, 4, 2, 2, 0, 2> zzxz; \
	detail::swizzle<vec, T, 4, 2, 2, 0, 3> zzxw; \
	detail::swizzle<vec, T, 4, 2, 2, 1, 0> zzyx; \
	detail::swizzle<vec, T, 4, 2, 2, 1, 1> zzyy; \
	detail::swizzle<vec, T, 4, 2, 2, 1, 2> zzyz; \
	detail::swizzle<vec, T, 4, 2, 2, 1, 3> zzyw; \
	detail::swizzle<vec, T, 4, 2, 2, 2, 0> zzzx; \
	detail::swizzle<vec, T, 4, 2, 2, 2, 1> zzzy; \
	detail::swizzle<vec, T, 4, 2, 2, 2, 2> zzzz; \
	detail::swizzle<vec, T, 4, 2, 2, 2, 3> zzzw; \
	detail::swizzle<vec, T, 4, 2, 2, 3, 0> zzwx; \
	detail::swizzle<vec, T, 4, 2, 2, 3, 1> zzwy; \
	detail::swizzle<vec, T, 4, 2, 2, 3, 2> zzwz; \
	detail::swizzle<vec, T, 4, 2, 2, 3, 3> zzww; \
	detail::swizzle<vec, T, 4, 2, 3, 0, 0> zwxx; \
	detail::swizzle<vec, T, 4, 2, 3, 0, 1> zwxy; \
	detail::swizzle<vec, T, 4, 2, 3, 0, 2> zwxz; \
	detail::swizzle<vec, T, 4, 2, 3, 0, 3> zwxw; \
	detail::swizzle<vec, T, 4, 2, 3, 1, 0> zwyx; \
	detail::swizzle<vec, T, 4, 2, 3, 1, 1> zwyy; \
	detail::swizzle<vec, T, 4, 2, 3, 1, 2> zwyz; \
	detail::swizzle<vec, T, 4, 2, 3, 1, 3> zwyw; \
	detail::swizzle<vec, T, 4, 2, 3, 2, 0> zwzx; \
	detail::swizzle<vec, T, 4, 2, 3, 2, 1> zwzy; \
	detail::swizzle<vec, T, 4, 2, 3, 2, 2> zwzz; \
	detail::swizzle<vec, T, 4, 2, 3, 2, 3> zwzw; \
	detail::swizzle<vec, T, 4, 2, 3, 3, 0> zwwx; \
	detail::swizzle<vec, T, 4, 2, 3, 3, 1> zwwy; \
	detail::swizzle<vec, T, 4, 2, 3, 3, 2> zwwz; \
	detail::swizzle<vec, T, 4, 2, 3, 3, 3> zwww; \
	detail::swizzle<vec, T, 4, 3, 0, 0, 0> wxxx; \
	detail::swizzle<vec, T, 4, 3, 0, 0, 1> wxxy; \
	detail::swizzle<vec, T, 4, 3, 0, 0, 2> wxxz; \
	detail::swizzle<vec, T, 4, 3, 0, 0, 3> wxxw; \
	detail::swizzle<vec, T, 4, 3, 0, 1, 0> wxyx; \
	detail::swizzle<vec, T, 4, 3, 0, 1, 1> wxyy; \
	detail::swizzle<vec, T, 4, 3, 0, 1, 2> wxyz; \
	detail::swizzle<vec, T, 4, 3, 0, 1, 3> wxyw; \
	detail::swizzle<vec, T, 4, 3, 0, 2, 0> wxzx; \
	detail::swizzle<vec, T, 4, 3, 0, 2, 1> wxzy; \
	detail::swizzle<vec, T, 4, 3, 0, 2, 2> wxzz; \
	detail::swizzle<vec, T, 4, 3, 0, 2, 3> wxzw; \
	detail::swizzle<vec, T, 4, 3, 0, 3, 0> wxwx; \
	detail::swizzle<vec, T, 4, 3, 0, 3, 1> wxwy; \
	detail::swizzle<vec, T, 4, 3, 0, 3, 2> wxwz; \
	detail::swizzle<vec, T, 4, 3, 0, 3, 3> wxww; \
	detail::swizzle<vec, T, 4, 3, 1, 0, 0> wyxx; \
	detail::swizzle<vec, T, 4, 3, 1, 0, 1> wyxy; \
	detail::swizzle<vec, T, 4, 3, 1, 0, 2> wyxz; \
	detail::swizzle<vec, T, 4, 3, 1, 0, 3> wyxw; \
	detail::swizzle<vec, T, 4, 3, 1, 1, 0> wyyx; \
	detail::swizzle<vec, T, 4, 3, 1, 1, 1> wyyy; \
	detail::swizzle<vec, T, 4, 3, 1, 1, 2> wyyz; \
	detail::swizzle<vec, T, 4, 3, 1, 1, 3> wyyw; \
	detail::swizzle<vec, T, 4, 3, 1, 2, 0> wyzx; \
	detail::swizzle<vec, T, 4, 3, 1, 2, 1> wyzy; \
	detail::swizzle<vec, T, 4, 3, 1, 2, 2> wyzz; \
	detail::swizzle<vec, T, 4, 3, 1, 2, 3> wyzw; \
	detail::swizzle<vec, T, 4, 3, 1, 3, 0> wywx; \
	detail::swizzle<vec, T, 4, 3, 1, 3, 1> wywy; \
	detail::swizzle<vec, T, 4, 3, 1, 3, 2> wywz; \
	detail::swizzle<vec, T, 4, 3, 1, 3, 3> wyww; \
	detail::swizzle<vec, T, 4, 3, 2, 0, 0> wzxx; \
	detail::swizzle<vec, T, 4, 3, 2, 0, 1> wzxy; \
	detail::swizzle<vec, T, 4, 3, 2, 0, 2> wzxz; \
	detail::swizzle<vec, T, 4, 3, 2, 0, 3> wzxw; \
	detail::swizzle<vec, T, 4, 3, 2, 1, 0> wzyx; \
	detail::swizzle<vec, T, 4, 3, 2, 1, 1> wzyy; \
	detail::swizzle<vec, T, 4, 3, 2, 1, 2> wzyz; \
	detail::swizzle<vec, T, 4, 3, 2, 1, 3> wzyw; \
	detail::swizzle<vec, T, 4, 3, 2, 2, 0> wzzx; \
	detail::swizzle<vec, T, 4, 3, 2, 2, 1> wzzy; \
	detail::swizzle<vec, T, 4, 3, 2, 2, 2> wzzz; \
	detail::swizzle<vec, T, 4, 3, 2, 2, 3> wzzw; \
	detail::swizzle<vec, T, 4, 3, 2, 3, 0> wzwx; \
	detail::swizzle<vec, T, 4, 3, 2, 3, 1> wzwy; \
	detail::swizzle<vec, T, 4, 3, 2, 3, 2> wzwz; \
	detail::swizzle<vec, T, 4, 3, 2, 3, 3> wzww; \
	detail::swizzle<vec, T, 4, 3, 3, 0, 0> wwxx; \
	detail::swizzle<vec, T, 4, 3, 3, 0, 1> wwxy; \
	detail::swizzle<vec, T, 4, 3, 3, 0, 2> wwxz; \
	detail::swizzle<vec, T, 4, 3, 3, 0, 3> wwxw; \
	detail::swizzle<vec, T, 4, 3, 3, 1, 0> wwyx; \
	detail::swizzle<vec, T, 4, 3, 3, 1, 1> wwyy; \
	detail::swizzle<vec, T, 4, 3, 3, 1, 2> wwyz; \
	detail::swizzle<vec, T, 4, 3, 3, 1, 3> wwyw; \
	detail::swizzle<vec, T, 4, 3, 3, 2, 0> wwzx; \
	detail::swizzle<vec, T, 4, 3, 3, 2, 1> wwzy; \
	detail::swizzle<vec, T, 4, 3, 3, 2, 2> wwzz; \
	detail::swizzle<vec, T, 4, 3, 3, 2, 3> wwzw; \
	detail::swizzle<vec, T, 4, 3, 3, 3, 0> wwwx; \
	detail::swizzle<vec, T, 4, 3, 3, 3, 1> wwwy; \
	detail::swizzle<vec, T, 4, 3, 3, 3, 2> wwwz; \
	detail::swizzle<vec, T, 4, 3, 3, 3, 3> wwww; \
	detail::swizzle<vec, T, 4, 0, 0> rr;         \
	detail::swizzle<vec, T, 4, 0, 1> rg;         \
	detail::swizzle<vec, T, 4, 0, 2> rb;         \
	detail::swizzle<vec, T, 4, 0, 3> ra;         \
	detail::swizzle<vec, T, 4, 1, 0> gr;         \
	detail::swizzle<vec, T, 4, 1, 1> gg;         \
	detail::swizzle<vec, T, 4, 1, 2> gb;         \
	detail::swizzle<vec, T, 4, 1, 3> ga;         \
	detail::swizzle<vec, T, 4, 2, 0> br;         \
	detail::swizzle<vec, T, 4, 2, 1> bg;         \
	detail::swizzle<vec, T, 4, 2, 2> bb;         \
	detail::swizzle<vec, T, 4, 2, 3> ba;         \
	detail::swizzle<vec, T, 4, 3, 0> ar;         \
	detail::swizzle<vec, T, 4, 3, 1> ag;         \
	detail::swizzle<vec, T, 4, 3, 2> ab;         \
	detail::swizzle<vec, T, 4, 3, 3> aa;         \
	detail::swizzle<vec, T, 4, 0, 0, 0> rrr;     \
	detail::swizzle<vec, T, 4, 0, 0, 1> rrg;     \
	detail::swizzle<vec, T, 4, 0, 0, 2> rrb;     \
	detail::swizzle<vec, T, 4, 0, 0, 3> rra;     \
	detail::swizzle<vec, T, 4, 0, 1, 0> rgr;     \
	detail::swizzle<vec, T, 4, 0, 1, 1> rgg;     \
	detail::swizzle<vec, T, 4, 0, 1, 2> rgb;     \
	detail::swizzle<vec, T, 4, 0, 1, 3> rga;     \
	detail::swizzle<vec, T, 4, 0, 2, 0> rbr;     \
	detail::swizzle<vec, T, 4, 0, 2, 1> rbg;     \
	detail::swizzle<vec, T, 4, 0, 2, 2> rbb;     \
	detail::swizzle<vec, T, 4, 0, 2, 3> rba;     \
	detail::swizzle<vec, T, 4, 0, 3, 0> rar;     \
	detail::swizzle<vec, T, 4, 0, 3, 1> rag;     \
	detail::swizzle<vec, T, 4, 0, 3, 2> rab;     \
	detail::swizzle<vec, T, 4, 0, 3, 3> raa;     \
	detail::swizzle<vec, T, 4, 1, 0, 0> grr;     \
	detail::swizzle<vec, T, 4, 1, 0, 1> grg;     \
	detail::swizzle<vec, T, 4, 1, 0, 2> grb;     \
	detail::swizzle<vec, T, 4, 1, 0, 3> gra;     \
	detail::swizzle<vec, T, 4, 1, 1, 0> ggr;     \
	detail::swizzle<vec, T, 4, 1, 1, 1> ggg;     \
	detail::swizzle<vec, T, 4, 1, 1, 2> ggb;     \
	detail::swizzle<vec, T, 4, 1, 1, 3> gga;     \
	detail::swizzle<vec, T, 4, 1, 2, 0> gbr;     \
	detail::swizzle<vec, T, 4, 1, 2, 1> gbg;     \
	detail::swizzle<vec, T, 4, 1, 2, 2> gbb;     \
	detail::swizzle<vec, T, 4, 1, 2, 3> gba;     \
	detail::swizzle<vec, T, 4, 1, 3, 0> gar;     \
	detail::swizzle<vec, T, 4, 1, 3, 1> gag;     \
	detail::swizzle<vec, T, 4, 1, 3, 2> gab;     \
	detail::swizzle<vec, T, 4, 1, 3, 3> gaa;     \
	detail::swizzle<vec, T, 4, 2, 0, 0> brr;     \
	detail::swizzle<vec, T, 4, 2, 0, 1> brg;     \
	detail::swizzle<vec, T, 4, 2, 0, 2> brb;     \
	detail::swizzle<vec, T, 4, 2, 0, 3> bra;     \
	detail::swizzle<vec, T, 4, 2, 1, 0> bgr;     \
	detail::swizzle<vec, T, 4, 2, 1, 1> bgg;     \
	detail::swizzle<vec, T, 4, 2, 1, 2> bgb;     \
	detail::swizzle<vec, T, 4, 2, 1, 3> bga;     \
	detail::swizzle<vec, T, 4, 2, 2, 0> bbr;     \
	detail::swizzle<vec, T, 4, 2, 2, 1> bbg;     \
	detail::swizzle<vec, T, 4, 2, 2, 2> bbb;     \
	detail::swizzle<vec, T, 4, 2, 2, 3> bba;     \
	detail::swizzle<vec, T, 4, 2, 3, 0> bar;     \
	detail::swizzle<vec, T, 4, 2, 3, 1> bag;     \
	detail::swizzle<vec, T, 4, 2, 3, 2> bab;     \
	detail::swizzle<vec, T, 4, 2, 3, 3> baa;     \
	detail::swizzle<vec, T, 4, 3, 0, 0> arr;     \
	detail::swizzle<vec, T, 4, 3, 0, 1> arg;     \
	detail::swizzle<vec, T, 4, 3, 0, 2> arb;     \
	detail::swizzle<vec, T, 4, 3, 0, 3> ara;     \
	detail::swizzle<vec, T, 4, 3, 1, 0> agr;     \
	detail::swizzle<vec, T, 4, 3, 1, 1> agg;     \
	detail::swizzle<vec, T, 4, 3, 1, 2> agb;     \
	detail::swizzle<vec, T, 4, 3, 1, 3> aga;     \
	detail::swizzle<vec, T, 4, 3, 2, 0> abr;     \
	detail::swizzle<vec, T, 4, 3, 2, 1> abg;     \
	detail::swizzle<vec, T, 4, 3, 2, 2> abb;     \
	detail::swizzle<vec, T, 4, 3, 2, 3> aba;     \
	detail::swizzle<vec, T, 4, 3, 3, 0> aar;     \
	detail::swizzle<vec, T, 4, 3, 3, 1> aag;     \
	detail::swizzle<vec, T, 4, 3, 3, 2> aab;     \
	detail::swizzle<vec, T, 4, 3, 3, 3> aaa;     \
	detail::swizzle<vec, T, 4, 0, 0, 0, 0> rrrr; \
	detail::swizzle<vec, T, 4, 0, 0, 0, 1> rrrg; \
	detail::swizzle<vec, T, 4, 0, 0, 0, 2> rrrb; \
	detail::swizzle<vec, T, 4, 0, 0, 0, 3> rrra; \
	detail::swizzle<vec, T, 4, 0, 0, 1, 0> rrgr; \
	detail::swizzle<vec, T, 4, 0, 0, 1, 1> rrgg; \
	detail::swizzle<vec, T, 4, 0, 0, 1, 2> rrgb; \
	detail::swizzle<vec, T, 4, 0, 0, 1, 3> rrga; \
	detail::swizzle<vec, T, 4, 0, 0, 2, 0> rrbr; \
	detail::swizzle<vec, T, 4, 0, 0, 2, 1> rrbg; \
	detail::swizzle<vec, T, 4, 0, 0, 2, 2> rrbb; \
	detail::swizzle<vec, T, 4, 0, 0, 2, 3> rrba; \
	detail::swizzle<vec, T, 4, 0, 0, 3, 0> rrar; \
	detail::swizzle<vec, T, 4, 0, 0, 3, 1> rrag; \
	detail::swizzle<vec, T, 4, 0, 0, 3, 2> rrab; \
	detail::swizzle<vec, T, 4, 0, 0, 3, 3> rraa; \
	detail::swizzle<vec, T, 4, 0, 1, 0, 0> rgrr; \
	detail::swizzle<vec, T, 4, 0, 1, 0, 1> rgrg; \
	detail::swizzle<vec, T, 4, 0, 1, 0, 2> rgrb; \
	detail::swizzle<vec, T, 4, 0, 1, 0, 3> rgra; \
	detail::swizzle<vec, T, 4, 0, 1, 1, 0> rggr; \
	detail::swizzle<vec, T, 4, 0, 1, 1, 1> rggg; \
	detail::swizzle<vec, T, 4, 0, 1, 1, 2> rggb; \
	detail::swizzle<vec, T, 4, 0, 1, 1, 3> rgga; \
	detail::swizzle<vec, T, 4, 0, 1, 2, 0> rgbr; \
	detail::swizzle<vec, T, 4, 0, 1, 2, 1> rgbg; \
	detail::swizzle<vec, T, 4, 0, 1, 2, 2> rgbb; \
	detail::swizzle<vec, T, 4, 0, 1, 2, 3> rgba; \
	detail::swizzle<vec, T, 4, 0, 1, 3, 0> rgar; \
	detail::swizzle<vec, T, 4, 0, 1, 3, 1> rgag; \
	detail::swizzle<vec, T, 4, 0, 1, 3, 2> rgab; \
	detail::swizzle<vec, T, 4, 0, 1, 3, 3> rgaa; \
	detail::swizzle<vec, T, 4, 0, 2, 0, 0> rbrr; \
	detail::swizzle<vec, T, 4, 0, 2, 0, 1> rbrg; \
	detail::swizzle<vec, T, 4, 0, 2, 0, 2> rbrb; \
	detail::swizzle<vec, T, 4, 0, 2, 0, 3> rbra; \
	detail::swizzle<vec, T, 4, 0, 2, 1, 0> rbgr; \
	detail::swizzle<vec, T, 4, 0, 2, 1, 1> rbgg; \
	detail::swizzle<vec, T, 4, 0, 2, 1, 2> rbgb; \
	detail::swizzle<vec, T, 4, 0, 2, 1, 3> rbga; \
	detail::swizzle<vec, T, 4, 0, 2, 2, 0> rbbr; \
	detail::swizzle<vec, T, 4, 0, 2, 2, 1> rbbg; \
	detail::swizzle<vec, T, 4, 0, 2, 2, 2> rbbb; \
	detail::swizzle<vec, T, 4, 0, 2, 2, 3> rbba; \
	detail::swizzle<vec, T, 4, 0, 2, 3, 0> rbar; \
	detail::swizzle<vec, T, 4, 0, 2, 3, 1> rbag; \
	detail::swizzle<vec, T, 4, 0, 2, 3, 2> rbab; \
	detail::swizzle<vec, T, 4, 0, 2, 3, 3> rbaa; \
	detail::swizzle<vec, T, 4, 0, 3, 0, 0> rarr; \
	detail::swizzle<vec, T, 4, 0, 3, 0, 1> rarg; \
	detail::swizzle<vec, T, 4, 0, 3, 0, 2> rarb; \
	detail::swizzle<vec, T, 4, 0, 3, 0, 3> rara; \
	detail::swizzle<vec, T, 4, 0, 3, 1, 0> ragr; \
	detail::swizzle<vec, T, 4, 0, 3, 1, 1> ragg; \
	detail::swizzle<vec, T, 4, 0, 3, 1, 2> ragb; \
	detail::swizzle<vec, T, 4, 0, 3, 1, 3> raga; \
	detail::swizzle<vec, T, 4, 0, 3, 2, 0> rabr; \
	detail::swizzle<vec, T, 4, 0, 3, 2, 1> rabg; \
	detail::swizzle<vec, T, 4, 0, 3, 2, 2> rabb; \
	detail::swizzle<vec, T, 4, 0, 3, 2, 3> raba; \
	detail::swizzle<vec, T, 4, 0, 3, 3, 0> raar; \
	detail::swizzle<vec, T, 4, 0, 3, 3, 1> raag; \
	detail::swizzle<vec, T, 4, 0, 3, 3, 2> raab; \
	detail::swizzle<vec, T, 4, 0, 3, 3, 3> raaa; \
	detail::swizzle<vec, T, 4, 1, 0, 0, 0> grrr; \
	detail::swizzle<vec, T, 4, 1, 0, 0, 1> grrg; \
	detail::swizzle<vec, T, 4, 1, 0, 0, 2> grrb; \
	detail::swizzle<vec, T, 4, 1, 0, 0, 3> grra; \
	detail::swizzle<vec, T, 4, 1, 0, 1, 0> grgr; \
	detail::swizzle<vec, T, 4, 1, 0, 1, 1> grgg; \
	detail::swizzle<vec, T, 4, 1, 0, 1, 2> grgb; \
	detail::swizzle<vec, T, 4, 1, 0, 1, 3> grga; \
	detail::swizzle<vec, T, 4, 1, 0, 2, 0> grbr; \
	detail::swizzle<vec, T, 4, 1, 0, 2, 1> grbg; \
	detail::swizzle<vec, T, 4, 1, 0, 2, 2> grbb; \
	detail::swizzle<vec, T, 4, 1, 0, 2, 3> grba; \
	detail::swizzle<vec, T, 4, 1, 0, 3, 0> grar; \
	detail::swizzle<vec, T, 4, 1, 0, 3, 1> grag; \
	detail::swizzle<vec, T, 4, 1, 0, 3, 2> grab; \
	detail::swizzle<vec, T, 4, 1, 0, 3, 3> graa; \
	detail::swizzle<vec, T, 4, 1, 1, 0, 0> ggrr; \
	detail::swizzle<vec, T, 4, 1, 1, 0, 1> ggrg; \
	detail::swizzle<vec, T, 4, 1, 1, 0, 2> ggrb; \
	detail::swizzle<vec, T, 4, 1, 1, 0, 3> ggra; \
	detail::swizzle<vec, T, 4, 1, 1, 1, 0> gggr; \
	detail::swizzle<vec, T, 4, 1, 1, 1, 1> gggg; \
	detail::swizzle<vec, T, 4, 1, 1, 1, 2> gggb; \
	detail::swizzle<vec, T, 4, 1, 1, 1, 3> ggga; \
	detail::swizzle<vec, T, 4, 1, 1, 2, 0> ggbr; \
	detail::swizzle<vec, T, 4, 1, 1, 2, 1> ggbg; \
	detail::swizzle<vec, T, 4, 1, 1, 2, 2> ggbb; \
	detail::swizzle<vec, T, 4, 1, 1, 2, 3> ggba; \
	detail::swizzle<vec, T, 4, 1, 1, 3, 0> ggar; \
	detail::swizzle<vec, T, 4, 1, 1, 3, 1> ggag; \
	detail::swizzle<vec, T, 4, 1, 1, 3, 2> ggab; \
	detail::swizzle<vec, T, 4, 1, 1, 3, 3> ggaa; \
	detail::swizzle<vec, T, 4, 1, 2, 0, 0> gbrr; \
	detail::swizzle<vec, T, 4, 1, 2, 0, 1> gbrg; \
	detail::swizzle<vec, T, 4, 1, 2, 0, 2> gbrb; \
	detail::swizzle<vec, T, 4, 1, 2, 0, 3> gbra; \
	detail::swizzle<vec, T, 4, 1, 2, 1, 0> gbgr; \
	detail::swizzle<vec, T, 4, 1, 2, 1, 1> gbgg; \
	detail::swizzle<vec, T, 4, 1, 2, 1, 2> gbgb; \
	detail::swizzle<vec, T, 4, 1, 2, 1, 3> gbga; \
	detail::swizzle<vec, T, 4, 1, 2, 2, 0> gbbr; \
	detail::swizzle<vec, T, 4, 1, 2, 2, 1> gbbg; \
	detail::swizzle<vec, T, 4, 1, 2, 2, 2> gbbb; \
	detail::swizzle<vec, T, 4, 1, 2, 2, 3> gbba; \
	detail::swizzle<vec, T, 4, 1, 2, 3, 0> gbar; \
	detail::swizzle<vec, T, 4, 1, 2, 3, 1> gbag; \
	detail::swizzle<vec, T, 4, 1, 2, 3, 2> gbab; \
	detail::swizzle<vec, T, 4, 1, 2, 3, 3> gbaa; \
	detail::swizzle<vec, T, 4, 1, 3, 0, 0> garr; \
	detail::swizzle<vec, T, 4, 1, 3, 0, 1> garg; \
	detail::swizzle<vec, T, 4, 1, 3, 0, 2> garb; \
	detail::swizzle<vec, T, 4, 1, 3, 0, 3> gara; \
	detail::swizzle<vec, T, 4, 1, 3, 1, 0> gagr; \
	detail::swizzle<vec, T, 4, 1, 3, 1, 1> gagg; \
	detail::swizzle<vec, T, 4, 1, 3, 1, 2> gagb; \
	detail::swizzle<vec, T, 4, 1, 3, 1, 3> gaga; \
	detail::swizzle<vec, T, 4, 1, 3, 2, 0> gabr; \
	detail::swizzle<vec, T, 4, 1, 3, 2, 1> gabg; \
	detail::swizzle<vec, T, 4, 1, 3, 2, 2> gabb; \
	detail::swizzle<vec, T, 4, 1, 3, 2, 3> gaba; \
	detail::swizzle<vec, T, 4, 1, 3, 3, 0> gaar; \
	detail::swizzle<vec, T, 4, 1, 3, 3, 1> gaag; \
	detail::swizzle<vec, T, 4, 1, 3, 3, 2> gaab; \
	detail::swizzle<vec, T, 4, 1, 3, 3, 3> gaaa; \
	detail::swizzle<vec, T, 4, 2, 0, 0, 0> brrr; \
	detail::swizzle<vec, T, 4, 2, 0, 0, 1> brrg; \
	detail::swizzle<vec, T, 4, 2, 0, 0, 2> brrb; \
	detail::swizzle<vec, T, 4, 2, 0, 0, 3> brra; \
	detail::swizzle<vec, T, 4, 2, 0, 1, 0> brgr; \
	detail::swizzle<vec, T, 4, 2, 0, 1, 1> brgg; \
	detail::swizzle<vec, T, 4, 2, 0, 1, 2> brgb; \
	detail::swizzle<vec, T, 4, 2, 0, 1, 3> brga; \
	detail::swizzle<vec, T, 4, 2, 0, 2, 0> brbr; \
	detail::swizzle<vec, T, 4, 2, 0, 2, 1> brbg; \
	detail::swizzle<vec, T, 4, 2, 0, 2, 2> brbb; \
	detail::swizzle<vec, T, 4, 2, 0, 2, 3> brba; \
	detail::swizzle<vec, T, 4, 2, 0, 3, 0> brar; \
	detail::swizzle<vec, T, 4, 2, 0, 3, 1> brag; \
	detail::swizzle<vec, T, 4, 2, 0, 3, 2> brab; \
	detail::swizzle<vec, T, 4, 2, 0, 3, 3> braa; \
	detail::swizzle<vec, T, 4, 2, 1, 0, 0> bgrr; \
	detail::swizzle<vec, T, 4, 2, 1, 0, 1> bgrg; \
	detail::swizzle<vec, T, 4, 2, 1, 0, 2> bgrb; \
	detail::swizzle<vec, T, 4, 2, 1, 0, 3> bgra; \
	detail::swizzle<vec, T, 4, 2, 1, 1, 0> bggr; \
	detail::swizzle<vec, T, 4, 2, 1, 1, 1> bggg; \
	detail::swizzle<vec, T, 4, 2, 1, 1, 2> bggb; \
	detail::swizzle<vec, T, 4, 2, 1, 1, 3> bgga; \
	detail::swizzle<vec, T, 4, 2, 1, 2, 0> bgbr; \
	detail::swizzle<vec, T, 4, 2, 1, 2, 1> bgbg; \
	detail::swizzle<vec, T, 4, 2, 1, 2, 2> bgbb; \
	detail::swizzle<vec, T, 4, 2, 1, 2, 3> bgba; \
	detail::swizzle<vec, T, 4, 2, 1, 3, 0> bgar; \
	detail::swizzle<vec, T, 4, 2, 1, 3, 1> bgag; \
	detail::swizzle<vec, T, 4, 2, 1, 3, 2> bgab; \
	detail::swizzle<vec, T, 4, 2, 1, 3, 3> bgaa; \
	detail::swizzle<vec, T, 4, 2, 2, 0, 0> bbrr; \
	detail::swizzle<vec, T, 4, 2, 2, 0, 1> bbrg; \
	detail::swizzle<vec, T, 4, 2, 2, 0, 2> bbrb; \
	detail::swizzle<vec, T, 4, 2, 2, 0, 3> bbra; \
	detail::swizzle<vec, T, 4, 2, 2, 1, 0> bbgr; \
	detail::swizzle<vec, T, 4, 2, 2, 1, 1> bbgg; \
	detail::swizzle<vec, T, 4, 2, 2, 1, 2> bbgb; \
	detail::swizzle<vec, T, 4, 2, 2, 1, 3> bbga; \
	detail::swizzle<vec, T, 4, 2, 2, 2, 0> bbbr; \
	detail::swizzle<vec, T, 4, 2, 2, 2, 1> bbbg; \
	detail::swizzle<vec, T, 4, 2, 2, 2, 2> bbbb; \
	detail::swizzle<vec, T, 4, 2, 2, 2, 3> bbba; \
	detail::swizzle<vec, T, 4, 2, 2, 3, 0> bbar; \
	detail::swizzle<vec, T, 4, 2, 2, 3, 1> bbag; \
	detail::swizzle<vec, T, 4, 2, 2, 3, 2> bbab; \
	detail::swizzle<vec, T, 4, 2, 2, 3, 3> bbaa; \
	detail::swizzle<vec, T, 4, 2, 3, 0, 0> barr; \
	detail::swizzle<vec, T, 4, 2, 3, 0, 1> barg; \
	detail::swizzle<vec, T, 4, 2, 3, 0, 2> barb; \
	detail::swizzle<vec, T, 4, 2, 3, 0, 3> bara; \
	detail::swizzle<vec, T, 4, 2, 3, 1, 0> bagr; \
	detail::swizzle<vec, T, 4, 2, 3, 1, 1> bagg; \
	detail::swizzle<vec, T, 4, 2, 3, 1, 2> bagb; \
	detail::swizzle<vec, T, 4, 2, 3, 1, 3> baga; \
	detail::swizzle<vec, T, 4, 2, 3, 2, 0> babr; \
	detail::swizzle<vec, T, 4, 2, 3, 2, 1> babg; \
	detail::swizzle<vec, T, 4, 2, 3, 2, 2> babb; \
	detail::swizzle<vec, T, 4, 2, 3, 2, 3> baba; \
	detail::swizzle<vec, T, 4, 2, 3, 3, 0> baar; \
	detail::swizzle<vec, T, 4, 2, 3, 3, 1> baag; \
	detail::swizzle<vec, T, 4, 2, 3, 3, 2> baab; \
	detail::swizzle<vec, T, 4, 2, 3, 3, 3> baaa; \
	detail::swizzle<vec, T, 4, 3, 0, 0, 0> arrr; \
	detail::swizzle<vec, T, 4, 3, 0, 0, 1> arrg; \
	detail::swizzle<vec, T, 4, 3, 0, 0, 2> arrb; \
	detail::swizzle<vec, T, 4, 3, 0, 0, 3> arra; \
	detail::swizzle<vec, T, 4, 3, 0, 1, 0> argr; \
	detail::swizzle<vec, T, 4, 3, 0, 1, 1> argg; \
	detail::swizzle<vec, T, 4, 3, 0, 1, 2> argb; \
	detail::swizzle<vec, T, 4, 3, 0, 1, 3> arga; \
	detail::swizzle<vec, T, 4, 3, 0, 2, 0> arbr; \
	detail::swizzle<vec, T, 4, 3, 0, 2, 1> arbg; \
	detail::swizzle<vec, T, 4, 3, 0, 2, 2> arbb; \
	detail::swizzle<vec, T, 4, 3, 0, 2, 3> arba; \
	detail::swizzle<vec, T, 4, 3, 0, 3, 0> arar; \
	detail::swizzle<vec, T, 4, 3, 0, 3, 1> arag; \
	detail::swizzle<vec, T, 4, 3, 0, 3, 2> arab; \
	detail::swizzle<vec, T, 4, 3, 0, 3, 3> araa; \
	detail::swizzle<vec, T, 4, 3, 1, 0, 0> agrr; \
	detail::swizzle<vec, T, 4, 3, 1, 0, 1> agrg; \
	detail::swizzle<vec, T, 4, 3, 1, 0, 2> agrb; \
	detail::swizzle<vec, T, 4, 3, 1, 0, 3> agra; \
	detail::swizzle<vec, T, 4, 3, 1, 1, 0> aggr; \
	detail::swizzle<vec, T, 4, 3, 1, 1, 1> aggg; \
	detail::swizzle<vec, T, 4, 3, 1, 1, 2> aggb; \
	detail::swizzle<vec, T, 4, 3, 1, 1, 3> agga; \
	detail::swizzle<vec, T, 4, 3, 1, 2, 0> agbr; \
	detail::swizzle<vec, T, 4, 3, 1, 2, 1> agbg; \
	detail::swizzle<vec, T, 4, 3, 1, 2, 2> agbb; \
	detail::swizzle<vec, T, 4, 3, 1, 2, 3> agba; \
	detail::swizzle<vec, T, 4, 3, 1, 3, 0> agar; \
	detail::swizzle<vec, T, 4, 3, 1, 3, 1> agag; \
	detail::swizzle<vec, T, 4, 3, 1, 3, 2> agab; \
	detail::swizzle<vec, T, 4, 3, 1, 3, 3> agaa; \
	detail::swizzle<vec, T, 4, 3, 2, 0, 0> abrr; \
	detail::swizzle<vec, T, 4, 3, 2, 0, 1> abrg; \
	detail::swizzle<vec, T, 4, 3, 2, 0, 2> abrb; \
	detail::swizzle<vec, T, 4, 3, 2, 0, 3> abra; \
	detail::swizzle<vec, T, 4, 3, 2, 1, 0> abgr; \
	detail::swizzle<vec, T, 4, 3, 2, 1, 1> abgg; \
	detail::swizzle<vec, T, 4, 3, 2, 1, 2> abgb; \
	detail::swizzle<vec, T, 4, 3, 2, 1, 3> abga; \
	detail::swizzle<vec, T, 4, 3, 2, 2, 0> abbr; \
	detail::swizzle<vec, T, 4, 3, 2, 2, 1> abbg; \
	detail::swizzle<vec, T, 4, 3, 2, 2, 2> abbb; \
	detail::swizzle<vec, T, 4, 3, 2, 2, 3> abba; \
	detail::swizzle<vec, T, 4, 3, 2, 3, 0> abar; \
	detail::swizzle<vec, T, 4, 3, 2, 3, 1> abag; \
	detail::swizzle<vec, T, 4, 3, 2, 3, 2> abab; \
	detail::swizzle<vec, T, 4, 3, 2, 3, 3> abaa; \
	detail::swizzle<vec, T, 4, 3, 3, 0, 0> aarr; \
	detail::swizzle<vec, T, 4, 3, 3, 0, 1> aarg; \
	detail::swizzle<vec, T, 4, 3, 3, 0, 2> aarb; \
	detail::swizzle<vec, T, 4, 3, 3, 0, 3> aara; \
	detail::swizzle<vec, T, 4, 3, 3, 1, 0> aagr; \
	detail::swizzle<vec, T, 4, 3, 3, 1, 1> aagg; \
	detail::swizzle<vec, T, 4, 3, 3, 1, 2> aagb; \
	detail::swizzle<vec, T, 4, 3, 3, 1, 3> aaga; \
	detail::swizzle<vec, T, 4, 3, 3, 2, 0> aabr; \
	detail::swizzle<vec, T, 4, 3, 3, 2, 1> aabg; \
	detail::swizzle<vec, T, 4, 3, 3, 2, 2> aabb; \
	detail::swizzle<vec, T, 4, 3, 3, 2, 3> aaba; \
	detail::swizzle<vec, T, 4, 3, 3, 3, 0> aaar; \
	detail::swizzle<vec, T, 4, 3, 3, 3, 1> aaag; \
	detail::swizzle<vec, T, 4, 3, 3, 3, 2> aaab; \
	detail::swizzle<vec, T, 4, 3, 3, 3, 3> aaaa;

#endif