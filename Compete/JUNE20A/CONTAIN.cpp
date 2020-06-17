//https://www.codechef.com/JUNE20A/problems/CONTAIN
// reference link --> https://codeforces.com/blog/entry/48868
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define MOD 1000000007
#define pii pair<ll, ll>
#define all(v) v.begin(), v.end()
#define ff first
#define ss second
#define pb push_back
template <class F>
struct Point
{
    F x, y;
    Point() : x(0), y(0) {}
    Point(const F &x, const F &y) : x(x), y(y) {}
    void swap(Point &other)
    {
        using std::swap;
        swap(x, other.x);
        swap(y, other.y);
    }
    template <class F1>
    explicit operator Point<F1>() const
    {
        return Point<F1>(static_cast<F1>(x), static_cast<F1>(y));
    }
    template <class F1>
    Point &operator=(const Point<F1> &other)
    {
        x = other.x;
        y = other.y;
        return *this;
    }
    template <class F1>
    Point &operator+=(const Point<F1> &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    template <class F1>
    Point &operator-=(const Point<F1> &other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    template <class F1>
    Point &operator*=(const F1 &factor)
    {
        x *= factor;
        y *= factor;
        return *this;
    }
    template <class F1>
    Point &operator/=(const F1 &factor)
    {
        x /= factor;
        y /= factor;
        return *this;
    }
};
template <class F>
int read(Point<F> &point) { return read(point.x, point.y) / 2; }
template <class F>
int write(const Point<F> &point) { return write(point.x, point.y); }

template <class F>
istream &operator>>(istream &is, Point<F> &point)
{
    return is >> point.x >> point.y;
}
template <class F>
ostream &operator<<(ostream &os, const Point<F> &point)
{
    return os << point.x << ' ' << point.y;
}

template <class F>
inline Point<F> makePoint(const F &x, const F &y) { return Point<F>(x, y); }
template <class F>
void swap(Point<F> &lhs, Point<F> &rhs) { lhs.swap(rhs); }

#define FUNC1(name, arg, expr) \
    template <class F>         \
    inline auto name(const arg)->decltype(expr) { return expr; }
#define FUNC2(name, arg1, arg2, expr) \
    template <class F1, class F2>     \
    inline auto name(const arg1, const arg2)->decltype(expr) { return expr; }
#define FUNC3(name, arg1, arg2, arg3, expr) \
    template <class F1, class F2, class F3> \
    inline auto name(const arg1, const arg2, const arg3)->decltype(expr) { return expr; }

FUNC1(operator-, Point<F> & point, makePoint(-point.x, -point.y))
FUNC2(operator+, Point<F1> & lhs, Point<F2> & rhs, makePoint(lhs.x + rhs.x, lhs.y + rhs.y))
FUNC2(operator-, Point<F1> & lhs, Point<F2> & rhs, makePoint(lhs.x - rhs.x, lhs.y - rhs.y))
FUNC2(operator*, F1 & factor, Point<F2> & rhs, makePoint(factor *rhs.x, factor *rhs.y))
FUNC2(operator*, Point<F1> & lhs, F2 & factor, makePoint(lhs.x *factor, lhs.y *factor))
FUNC2(operator/, Point<F1> & lhs, F2 & factor, makePoint(lhs.x / factor, lhs.y / factor))

FUNC2(operator*, Point<F1> & lhs, Point<F2> & rhs, lhs.x * rhs.x + lhs.y * rhs.y)
FUNC2(operator^, Point<F1> & lhs, Point<F2> & rhs, lhs.x * rhs.y - lhs.y * rhs.x)

// < 0 if rhs <- lhs counter-clockwise, 0 if collinear, > 0 if clockwise.
FUNC2(ccw, Point<F1> &lhs, Point<F2> &rhs, rhs ^ lhs)
FUNC3(ccw, Point<F1> &lhs, Point<F2> &rhs, Point<F3> &origin, ccw(lhs - origin, rhs - origin))

FUNC2(operator==, Point<F1> & lhs, Point<F2> & rhs, lhs.x == rhs.x && lhs.y == rhs.y)
FUNC2(operator!=, Point<F1> & lhs, Point<F2> & rhs, !(lhs == rhs))

FUNC2(operator<, Point<F1> & lhs, Point<F2> & rhs, lhs.y<rhs.y ||(lhs.y == rhs.y && lhs.x < rhs.x))
FUNC2(operator>, Point<F1> & lhs, Point<F2> & rhs, rhs<lhs)
FUNC2(operator<=, Point<F1> & lhs, Point<F2> & rhs, !(lhs > rhs))
FUNC2(operator>=, Point<F1> & lhs, Point<F2> & rhs, !(lhs < rhs))

// Angles and rotations (counter-clockwise).
FUNC1(angle, Point<F> &point, atan2(point.y, point.x))
FUNC2(angle, Point<F1> &lhs, Point<F2> &rhs, atan2(lhs ^ rhs, lhs *rhs))
FUNC3(angle, Point<F1> &lhs, Point<F2> &rhs, Point<F3> &origin, angle(lhs - origin, rhs - origin))
FUNC3(rotate, Point<F1> &point, F2 &angleSin, F3 &angleCos, makePoint(angleCos *point.x - angleSin * point.y, angleSin *point.x + angleCos * point.y))
FUNC2(rotate, Point<F1> &point, F2 &angle, rotate(point, sin(angle), cos(angle)))
FUNC3(rotate, Point<F1> &point, F2 &angle, Point<F3> &origin, origin + rotate(point - origin, angle))
FUNC1(perp, Point<F> &point, makePoint(-point.y, point.x))

// Distances.
FUNC1(abs, Point<F> &point, point *point)
FUNC1(norm, Point<F> &point, sqrt(abs(point)))
FUNC2(dist, Point<F1> &lhs, Point<F2> &rhs, norm(lhs - rhs))
FUNC2(dist2, Point<F1> &lhs, Point<F2> &rhs, abs(lhs - rhs))
FUNC2(bisector, Point<F1> &lhs, Point<F2> &rhs, lhs *norm(rhs) + rhs * norm(lhs))

#undef FUNC1
#undef FUNC2
#undef FUNC3
template <class F>
using Polygon = vector<Point<F>>;
inline int prev(int i, int n) { return i == 0 ? n - 1 : i - 1; }
inline int next(int i, int n) { return i == n - 1 ? 0 : i + 1; }
template <class T>
inline int sgn(const T &x) { return (T(0) < x) - (x < T(0)); }
template <class F>
Polygon<F> convexHull(Polygon<F> points)
{
    if(points.size()< 3)
        return {};
    sort(begin(points), end(points));
    Polygon<F> hull;
    hull.reserve(points.size() + 1);
    for (int phase = 0; phase < 2; ++phase)
    {
        auto start = hull.size();
        for (auto &point : points)
        {
            while (hull.size() >= start + 2 && ccw(point, hull.back(), hull[hull.size() - 2]) <= 0)
                hull.pop_back();
            hull.push_back(point);
        }
        hull.pop_back();
        reverse(begin(points), end(points));
    }
    if (hull.size() == 2 && hull[0] == hull[1])
        hull.pop_back();
    // reverse(begin(hull), end(hull));
    return hull;
}
template <class F1, class F2>
int pointVsConvexPolygon(const Point<F1> &point, const Polygon<F2> &poly, int top)
{
    if (point < poly[0] || point > poly[top])
        return 1;
    auto orientation = ccw(point, poly[top], poly[0]);
    if (orientation == 0)
    {
        // return 0;
        if (point == poly[0] || point == poly[top])
            return 0;
        return top == 1 || top + 1 == poly.size() ? 0 : -1;
    }
    else if (orientation < 0)
    {
        auto itRight = lower_bound(begin(poly) + 1, begin(poly) + top, point);
        return sgn(ccw(itRight[0], point, itRight[-1]));
    }
    else
    {
        auto itLeft = upper_bound(poly.rbegin(), poly.rend() - top - 1, point);
        return sgn(ccw(itLeft == poly.rbegin() ? poly[0] : itLeft[-1], point, itLeft[0]));
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q,i,x,y;
        cin >> n >> q;
        Polygon<ll> A(n), convex, extra;
        for (i = 0; i < n; i++)
        {
            cin >> x >> y;
            A[i] = Point<ll>(x, y);
        }
        vector<bool> ansFound(q, false);
        vector<ll> ans(q, 0);
        Polygon<ll> queries(q);
        for (i = 0; i < q; i++)
        {
            cin >> x >> y;
            queries[i] = Point<ll>(x, y);
        }
        unordered_map<ll, unordered_set<ll>> mp;
        ll top, minX, minY,res;
        while (true)
        {
            convex = convexHull(A);
            if (convex.size() < 3)
                break;
            mp.clear();
            extra.clear();
            top = -1;
            minX = LLONG_MIN, minY = LLONG_MIN;
            for (i = 0; i < convex.size(); i++)
            {
                if (convex[i].y > minY)
                {
                    top = i;
                    minY = convex[i].y;
                    minX = convex[i].x;
                }
                else if (convex[i].y == minY && convex[i].x > minX)
                {
                    top = i;
                    minY = convex[i].y;
                    minX = convex[i].x;
                }
                mp[convex[i].x].insert(convex[i].y);
            }
            for(i=0;i<A.size();i++)
            {
                res = pointVsConvexPolygon(A[i], convex, top);
                if(res==0)
                {
                    mp[A[i].x].insert(A[i].y);
                }
            }
            for (i = 0; i < A.size(); i++)
            {
                if (mp.count(A[i].x) > 0)
                {
                    if (mp[A[i].x].count(A[i].y) == 0)
                    {
                        extra.push_back(A[i]);
                    }
                }
                else
                {
                    extra.pb(A[i]);
                }
            }
            for(i=0;i<queries.size();i++)
            {
                if(ansFound[i]==false)
                {
                    res = pointVsConvexPolygon(queries[i],convex,top);
                    if(res == -1)
                    {
                        ans[i]++;
                    }
                    else
                    {
                        ansFound[i]=true;
                    }
                    
                }
            }
            A = extra;
        }
        for(i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}