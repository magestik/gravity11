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
