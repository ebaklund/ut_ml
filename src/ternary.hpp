
#pragma once

#include <algorithm>


inline float b_to_t(float b)
{
    return b * 2.f - 1.f;
}

inline float t_to_b(float t)
{
    return (t + 1.f) * 0.5f;
}

inline float tz_bump(float t1, float t2)
{
    return (1.0f - t1 * t1) * (1.0f - t2 * t2) * 0.5f;
}

inline float tand(float t1, float t2)
{
    return (1.0f + t1) * (1.0f + t2) * 0.5f - 1.0f;
}

inline float tz_and(float t1, float t2)
{
    //return tand(t1, t2) + tz_bump(t1, t2);
    //return (1.0f + t1) * (1.0f + t2) * 0.5f - 1.0f + (1.0f - t1 * t1) * (1.0f - t2 * t2) * 0.5f;
    //return ((1.0f + t1) * (1.0f + t2) + (1.0f - t1 * t1) * (1.0f - t2 * t2))  * 0.5f - 1.0f;
    //return (1.0f + t1 + t2 + t1*t2 + (1.0f - t1 * t1) * (1.0f - t2 * t2))  * 0.5f - 1.0f;
    //return (1.0f + t1 + t2 + t1*t2 + 1.0f - t1*t1 - t2*t2 + t1*t1*t2*t2)  * 0.5f - 1.0f;
    //return (t1 - t1*t1 + t1*t2 + t2 - t2*t2 + t1*t1*t2*t2) * 0.5f;
    float t11 = t1 * t1;
    float t22 = t2 * t2;
    return (t1 - t11 + t1*t2 + t2 - t22 + t11*t22) * 0.5f; // Saves one substraction and one multiplication
}

inline float twandz(float w1, float w2, float t1, float t2)
{
    // return tz_and(w1 * t1, w2 * t2);
    // return tbumpz(w1 * t1, w2 * t2) + tand(w1 * t1, w2 * t2);
    // return ((1.0f - w1 * w1 * t1 * t1) * (1.0f - w2 * w2 * t2 * t2) * 0.5f) + ((1.0f + w1 * t1) * (1.0f + w2 * t2) * 0.5f - 1.0f);
    // return (((1.0f - w1 * w1 * t1 * t1) * (1.0f - w2 * w2 * t2 * t2) * 0.5f) + ((1.0f + w1 * t1) * (1.0f + w2 * t2) * 0.5f - 1.0f));
    // return (((1.0f - w1 * w1 * t1 * t1) * (1.0f - w2 * w2 * t2 * t2) * 0.5f) + ((1.0f + w1 * t1) * (1.0f + w2 * t2) * 0.5f)) - 1.0f;
    // return (((1.0f - w1 * w1 * t1 * t1) * (1.0f - w2 * w2 * t2 * t2)) + ((1.0f + w1 * t1) * (1.0f + w2 * t2))) * 0.5f - 1.0f;
    float wt1 = w1 * t1;
    float wt2 = w2 * t2;
    return (((1.0f - wt1 * wt1) * (1.0f - wt2 * wt2)) + ((1.0f + wt1) * (1.0f + wt2))) * 0.5f - 1.0f;
}

inline float tz_nif1(float t1, float t2)
{
    return twandz(-1.0f, 1.0f, t1, t2);
}

inline float tz_nif2(float t1, float t2)
{
    return twandz(1.0f, -1.0f, t1, t2);
}

inline float tz_nor(float t1, float t2)
{
    return twandz(-1.0f, -1.0f, t1, t2);
}

inline float tmin3(float t1, float t2)
{
    float mt = std::min(t1, t2);
    return mt * mt * mt;
}

inline void dtwandz_dw(float w1, float w2, float t1, float t2, float& dw1, float& dw2)
{
    // return tz_and(w1 * t1, w2 * t2);
    // return tbumpz(w1 * t1, w2 * t2) + tand(w1 * t1, w2 * t2);
    // return ((1.0f - w1 * w1 * t1 * t1) * (1.0f - w2 * w2 * t2 * t2) * 0.5f) + ((1.0f + w1 * t1) * (1.0f + w2 * t2) * 0.5f - 1.0f);
    // d_tz_and/d_w1: (((1.0f - w1 * w1 * t1 * t1) * (1.0f - w2 * w2 * t2 * t2) * 0.5f) + ((1.0f + w1 * t1) * (1.0f + w2 * t2) * 0.5f - 1.0f))'
    // d_tz_and/d_w1: ((1.0f - w1 * w1 * t1 * t1) * (1.0f - w2 * w2 * t2 * t2) * 0.5f)' + ((1.0f + w1 * t1) * (1.0f + w2 * t2) * 0.5f)' - 1.0f'
    // d_tz_and/d_w1: ((1.0f - w1 * w1 * t1 * t1) * (1.0f - w2 * w2 * t2 * t2) * 0.5f)' + ((1.0f + w1 * t1) * (1.0f + w2 * t2) * 0.5f)'
    // d_tz_and/d_w1: [((1.0f - w1 * w1 * t1 * t1) * (1.0f - w2 * w2 * t2 * t2))' + ((1.0f + w1 * t1) * (1.0f + w2 * t2))'] * 0.5f
    // d_tz_and/d_w1: [(1.0f - w1 * w1 * t1 * t1)' * (1.0f - w2 * w2 * t2 * t2) + (1.0f + w1 * t1)' * (1.0f + w2 * t2)] * 0.5f
    // d_tz_and/d_w1: [(1.0f' - (w1 * w1 * t1 * t1)') * (1.0f - w2 * w2 * t2 * t2) + (1.0f' + (w1 * t1)') * (1.0f + w2 * t2)] * 0.5f
    // d_tz_and/d_w1: [-(w1 * w1 * t1 * t1)' * (1.0f - w2 * w2 * t2 * t2) + (w1 * t1)' * (1.0f + w2 * t2)] * 0.5f
    // d_tz_and/d_w1: [-(2 * w1 * t1 * t1) * (1.0f - w2 * w2 * t2 * t2) + t1 * (1.0f + w2 * t2)] * 0.5f
    // d_tz_and/d_w1: -(w1 * t1 * t1) * (1.0f - w2 * w2 * t2 * t2) + t1 * (1.0f + w2 * t2) * 0.5f
    // d_tz_and/d_w1: t1 * (-(w1 * t1) * (1.0f - w2 * w2 * t2 * t2) + (1.0f + w2 * t2) * 0.5f)
    // d_tz_and/d_w1: t1 * (-w1 * t1 * (1.0f - w2 * w2 * t2 * t2) + (1.0f + w2 * t2) * 0.5f)
    // d_tz_and/d_w1: t1 * (-wt1 * (1.0f - wt2 * wt2) + (1.0f + wt2) * 0.5f)

    float wt1 = w1 * t1;
    float wt2 = w2 * t2;
    dw1 = t1 * (- wt1 * (1.0f - wt2 * wt2) + (1.0f + wt2) * 0.5f);
    dw2 = t2 * (- wt2 * (1.0f - wt1 * wt1) + (1.0f + wt1) * 0.5f);
}

inline float rnd_pert()
{
    static thread_local uint32_t rnd = 123456789;
    rnd = rnd * 1103515245U + 12345U;

    float pert = (int)(rnd & 1) * 2 - 1;
    return pert;
}

inline float w_updated(float dw, float diff, float w)
{
    const float throttle = 0.99f;
    const float heat = 0.001f;

    float correction = (rnd_pert() * heat + throttle * dw) * diff;
    float w_updated = std::clamp(w + correction, -1.f, 1.f);
    return w_updated;
}

inline void twlearnz(float target, float t1, float t2, float& w1, float& w2)
{
    float dw1;
    float dw2;
    dtwandz_dw(w1, w2, t1, t2, dw1, dw2);

    float diff = target - tz_and(w1 * t1, w2 * t2);

    w1 = w_updated(dw1, diff, w1);
    w2 = w_updated(dw2, diff, w2);
}

inline bool teq(float a, float b, float e)
{
    return std::abs(a - b) <= e;
}
