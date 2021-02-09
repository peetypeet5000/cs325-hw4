#include "activity.h"

using std::vector;
using std::cout;


/*
 * Driver function for activity selection. This reads the data in from act.txt, sorts
 * it in decresing start time order, than runs the activity selection algorithm on it, 
 * printing the results to the terminal
 */
int main() {
    //read in data
    vector<vector<int>> data;
    read_file(data);

    int line_in_data = 0;
    int set = 0;

    //For each test case
    do {
        //get length of data set, advance to next line
        int data_size = data[line_in_data++][0];

        //make temp vector for storing specific data
        vector<activity> activities(data_size);
        
        //read each data set into data_set
        for(int i = 0; i < data_size; i++) {
            activities[i].activity_number = data[line_in_data][0];
            activities[i].start_time = data[line_in_data][1];
            activities[i].end_time = data[line_in_data][2];
            line_in_data++;
        }

        //sort data
        merge_sort(activities, 0, activities.size() - 1);

        //do algorithm
        vector<activity> selected = activity_selection(activities);

        //print results
        cout << "\nSet: " << set << "\n";
        cout << "Number of activities selected: " << selected.size() << "\nActivities: ";
        for(int i = (int)selected.size() - 1; i >= 0; i--) {
            cout << selected[i].activity_number << " ";
        }
        cout << "\n";

        set++;
    } while (line_in_data < (int)data.size());
}




/*
 * This function takes a vector of activity structs and selects the maximum
 * number it can without overlapping.
 * 
 * Complexity: Θ(n)
 *
 * Params:
 *   activities - a vector of activities that are sorted in decresing start time
 */
vector<activity> activity_selection(vector<activity> activities) {
    //vector for storing selected activities
    vector<activity> selected;

    //always select the first activity (last to start)
    selected.push_back(activities[0]);

    //loop thru all activies sorted by decresing start time
    for(int m = 1; m < (int)activities.size(); m++) {
        //if activity ends before existing activity starts, add it
        if(activities[m].end_time <= selected[selected.size() - 1].start_time) {
            selected.push_back(activities[m]);
        }
    }

    return selected;
}