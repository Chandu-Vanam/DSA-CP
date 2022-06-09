bool solve(int sx,int sy,int dx,int dy)
{
    if(sx==dx && sy==dy)
        return true;
    
    if(sx>dx || sy>dy)
        return false;
    
    if(dx>dy)
    return solve(sx,sy,dx-dy,dy);
    	// solve(sx-sy,sy,dx,dy);
        else
    return solve(sx,sy,dx,dy-dx);
        // solve(sx,sy-sx,dx,dy);
}

bool reachDestination(int sx, int sy, int dx, int dy) {
    // Write your code here
    return solve(sx,sy,dx,dy);
}
