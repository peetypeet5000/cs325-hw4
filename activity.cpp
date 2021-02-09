#include "activity.h"

using std::vector;
using std::cout;

int main() {
    
    vector<vector<int>> data;
    read_file(data);

    auto line_in_file = 0;
    int set = 0;

    //T Test Cases  (first int in file)
    do {
        //get length of data set, advance to next line
        int data_size = data[line_in_file++][0];

        //make temp vector for storing specific data
        vector<activity> activities(data_size);
        
        //read each data set into data_set
        for(int i = 0; i < data_size; i++) {
            activities[i].activity_number = data[line_in_file][0];
            activities[i].start_time = data[line_in_file][1];
            activities[i].end_time = data[line_in_file][2];
            line_in_file++;
        }

        cout << "\nSet: " << set << "\n";

        //sort data
        merge_sort(activities, 0, activities.size() - 1);

        //do algorithm
        vector<activity> selected = activity_selection(activities);

        //print results
        cout << "Number of activities selected: " << selected.size() << "\nActivities: ";
        for(int i = (int)selected.size() - 1; i >= 0; i--) {
            cout << selected[i].activity_number << " ";
        }
        cout << "\n";

        set++;
    } while (line_in_file < (int)data.size());
}



vector<activity> activity_selection(vector<activity> activities) {
    vector<activity> selected;
    int total_activities = activities.size();

    selected.push_back(activities[0]);

    //loop thru all activies sorted by decresing start time
    for(int m = 1; m < total_activities; m++) {
        //if activity ends before existing activity starts, add it
        if(activities[m].end_time <= selected[selected.size() - 1].start_time) {
            selected.push_back(activities[m]);
        }
    }

    return selected;
}