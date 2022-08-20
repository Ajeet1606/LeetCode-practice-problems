class Solution
{
    public:
        int minRefuelStops(int target, int currFuel, vector<vector < int>> &stations)
        {
            vector<pair<int, int>> fuelWiseSortedStations;
            unordered_map<int, bool>taken;
            for (auto s: stations){
                fuelWiseSortedStations.push_back({ s[1], s[0] });
                taken[s[0]] = false;
            }

            sort(fuelWiseSortedStations.rbegin(), fuelWiseSortedStations.rend());

            int currPosition = 0;
            long fuelTaken = 0;
            bool ok = true, notPossible = false;
            while (ok){
                cout<<"currFuel"<<currFuel<<endl;
                cout<<"currPosition"<<currPosition<<endl;
                long distanceCovered = currFuel + currPosition;
                cout<<"distanceCovered"<<distanceCovered<<endl;
                
               	//find distance from next stop
                long nextStop = target;
                for (auto s: stations){
                    if (s[0] > distanceCovered){
                        nextStop = s[0];
                        break;
                    }
                }
                cout<<"nextStop"<<nextStop<<endl;
                long distanceToCover = nextStop - distanceCovered;
                cout<<"distanceToCover"<<distanceToCover<<endl;
                long fuelNeeded = distanceToCover;

               	//check if we've fuelNeeded amount of fuel before fuel ends
                long sumOfFuel = 0;
                for (auto s: stations){
                    if (taken[s[0]] == false and s[0] <= distanceCovered){
                        sumOfFuel += s[1];
                    }
                }
                cout<<"sumOfFuel"<<sumOfFuel<<endl;
                if (sumOfFuel < fuelNeeded){
                    notPossible = true; 
                    ok = false;
                    continue;
                }

               	//pick fuel
                long collectFuel = 0;
                for (auto f: fuelWiseSortedStations){
                    if (fuelNeeded <= collectFuel){
                        break;
                    }
                    if (taken[f.second] == false and f.second <= distanceCovered){
                        fuelTaken++;
                        collectFuel += f.first;
                        taken[f.second] = true;
                    }
                }
                cout<<"collectFuel"<<collectFuel<<endl;
                currFuel = collectFuel;
                currPosition = distanceCovered;

                if (currPosition + currFuel >= target)
                {
                    break;
                }
            }
            return notPossible? -1: fuelTaken;
        }
};