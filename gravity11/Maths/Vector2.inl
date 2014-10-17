// -----------------------------------------
// Vector op Vector
// -----------------------------------------

inline vec2 operator * (const vec2 & a, const vec2 & b)
{
	return(vec2(a.x * b.x, a.y * b.y));
}

inline vec2 operator / (const vec2 & a, const vec2 & b)
{
	return(vec2(a.x / b.x, a.y / b.y));
}

inline vec2 operator + (const vec2 & a, const vec2 & b)
{
	return(vec2(a.x + b.x, a.y + b.y));
}

inline vec2 operator - (const vec2 & a, const vec2 & b)
{
	return(vec2(a.x - b.x, a.y - b.y));
}

// -----------------------------------------
// Vector op Scalar
// -----------------------------------------

inline vec2 operator * (const vec2 & a, float s)
{
	return(vec2(a.x * s, a.y * s));
}

inline vec2 operator * (float s, const vec2 & b)
{
	return(vec2(s * b.x, s * b.y));
}

inline vec2 operator / (const vec2 & a, float s)
{
	return(vec2(a.x / s, a.y / s));
}

inline vec2 operator / (float s, const vec2 & b)
{
	return(vec2(s / b.x, s / b.y));
}

// -----------------------------------------
// Vector functions
// -----------------------------------------

inline float norm(const vec2 & v)
{
    return(sqrtf(v.x * v.x + v.y * v.y));
}

inline vec2 normalize(const vec2 & v)
{
    return(v / norm(v));
}

inline float dot(const vec2 & v1, const vec2 & v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

inline float cross(const vec2 & v1, const vec2 & v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}
