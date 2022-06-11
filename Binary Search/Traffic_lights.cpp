
/*
	Time Complexity : O(N * log(X))
	Space Complexity : O(N)

	Where 'N' is the number of lights to be installed 
    and 'X' is the length of road.
*/

vector<int> trafficLights(int n, int x, vector<int> &pos)
{
	set<int> lights;
	multiset<int> distance;

	lights.insert(0);
	lights.insert(x);
	distance.insert(x);

	vector<int> res ;

	for (int i = 0; i < n; ++i)
	{
		int p = pos[i] ;
		set<int>::iterator greaterPos = lights.upper_bound(p);
		set<int>::iterator smallerPos = greaterPos;
		// Shifting the iterator to previous position.
		--smallerPos;

		// Inserting the new distance positions and removing the previous one.
		distance.erase(distance.find(*greaterPos - *smallerPos));
		distance.insert(p - *smallerPos);
		distance.insert(*greaterPos - p);
		lights.insert(p);

		set<int>::iterator ans = distance.end();
		--ans;
		res.push_back(*ans) ;
	}

	return res ;
}
