int cross(PII a, PII b, PII c){
	return (b.X-a.X)*(c.Y-a.Y)-(b.Y-a.Y)*(c.X-a.X);
}

}
void convex_hull(){
    sort(v.begin(), v.end());
    int top = 0;
    for (int i = 0; i < v.size(); i++){
        while (top >= 2 && cross(hull[top-2], hull[top-1], v[i]) <= 0)
            hull.pop_back(), top--;
        hull.emplace_back(v[i]), top++;
    }
    for (int i = v.size()-2, t=top+1; i >= 0; i--){
        while (top >= t && cross(hull[top-2], hull[top-1], v[i]) <= 0)
            hull.pop_back(), top--;
        hull.emplace_back(v[i]), top++;
    }
    // hull.pop_back()
}