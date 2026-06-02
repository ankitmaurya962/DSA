class Solution
{
    public:
        int earliestFinishTime(vector<int> &landStartTime,
            vector<int> &landDuration,
            vector<int> &waterStartTime,
            vector<int> &waterDuration)
        {

            int minPossibleTime = INT_MAX;

           	// Land first -> Water second
            for (int i = 0; i < landStartTime.size(); i++)
            {

                int firstR = landDuration[i] + landStartTime[i];

                for (int j = 0; j < waterStartTime.size(); j++)
                {

                    if (firstR <= waterStartTime[j])
                    {
                        minPossibleTime = min(minPossibleTime,
                            waterStartTime[j] + waterDuration[j]);
                    }
                    else
                    {
                        minPossibleTime =
                            min(minPossibleTime, firstR + waterDuration[j]);
                    }
                }
            }

           	// Water first -> Land second
            for (int i = 0; i < waterStartTime.size(); i++)
            {

                int firstR = waterDuration[i] + waterStartTime[i];

                for (int j = 0; j < landStartTime.size(); j++)
                {

                    if (firstR <= landStartTime[j])
                    {
                        minPossibleTime = min(minPossibleTime,
                            landStartTime[j] + landDuration[j]);
                    }
                    else
                    {
                        minPossibleTime =
                            min(minPossibleTime, firstR + landDuration[j]);
                    }
                }
            }

            return minPossibleTime;
        }
};