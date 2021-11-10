/*
        - Book a meeting with or without room
        - Find available meeting rooms
        - Cancel a meeting
        - View meetings booked by user and invited to

        
        Conditions
        - Only free meeting rooms for the given time slots can be booked.
        - an user can be part of multiple meetings - as participant
        - An user cannot book two rooms at the same time slot

    
    */

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;

// INTERFACES

class IRoom {
    public:
        unsigned long getId();
        string getLocation();
};

class IMeeting {

public:
    unsigned long long meeting_id;
    time_t start_time;
    time_t end_time;
    unsigned long long scheduler_user_id;
    IRoom *pRoom;
    string metaData;
};

class IMeetingMgr {

	public:
		vector<IMeeting> getMeetings(time_t startTime, time_t endTime);

		vector<IMeeting> getMeetings(unsigned long user_id);

        vector<IMeeting> getMeetings();	// uber level


        IMeeting createMeeting(time_t startTime, time_t endTime, IRoom *pRoom/* = nullptr*/);

        bool cancelMeeting(unsigned long long booking_id);

        vector<IRoom> getMeetingRooms(time_t startTime, time_t endTime);

        // --> this is where we read from the data provider
        void init();    
};

enum DataSource {

    File, //
    DB,
    Other
};


class IDataProvider {

    vector<IRoom> getRooms();
    vector<IMeeting> getMeetings(time_t start, time_t end);
};

class ISQLPrvi : public IDataProvider {

    
};




// IMPLEMENTATIONS

class Meeting : public IMeeting {
    public:
        unsigned long long get_meeting_id();
        void setStartTime(time_t start_time);
        void setEndTime(time_t end_time);
        void setScheduler(unsigned long long scheduler_user_id);
        void setRoom(IRoom *pRoom);
        void setAdditionalData(string metaData); 

        // getters follow
 };

class MeetingMgr : public IMeetingMgr {
    DataSource _src;
    unsigned long _user_id
    IDataProvider *pDp = nullptr;

    public:

    MeetingMgr(unsigned long user_id, DataSource dataSrc) {

        _src = source;
        _user_id = user_id;
        pDp = getDataProvider();
        if(pDp = nullptr) throw std::exception("caould nt instantiate");
    }

    // void init() {
    //     // depending on the data source we want to gather all the details
    //     switch(_src) {
    //         case DB:
    //             IDataProvider *pDp = getDataProvider();
    //             if(pDP) {
                    
    //             }
    //         break;
    //         case File: 
    //         case Other:
    //         default:
    //          break;

    //     }
    // }



    vector<IMeeting> getMeetings(time_t startTime, time_t endTime) {

        vector<IMeeting> meetings;
        // goto the data store via data provider interface & get the raw data first
        // apply the biz logic constraint(s)


        return meetings;
    }

		vector<IMeeting> getMeetings(unsigned long user_id);

        vector<IMeeting> getMeetings();	// uber level

    IMeeting createMeeting(time_t startTime, time_t endTime, IRoom *pRoom) {

        vector<IMeeting *> meetings = getMeetings(start_time, end_time);

        // if(meetings.size() != 0) {
        //     // also log!
        //     return nullptr;
        // }
        IMeeting *pMeeting = nullptr;

        // {9-10, 10-11, 11-11.30, 4.30-5}
        // I want 4-4.45
        for(auto &m : meetings) {
            if(m.end_time < start_time) continue;

            if(end_time > m.start_time) {
                // conflict!
                break;
            }

            // this is where we do the booking!
            Meeting meeting;
            meeting.start_time = start_time;
            meeting.end_time = end_time;
            meeting.scheduler_user_id = _user_id;
            meeting.metaData = "Successful";
            if(pRoom)
                meeting.room = pRoom;

            // persist the meeting object via data access layer to data store
            // instantiate pMeeting with the meeeting object
            break;
        }   
        return pMeeting;

    }


};




int main() {

    cout << "Meeting booking" << endl;
 
    // init methd to populate the in memory data --> this is where we read from the data provider

    init();
    


    return 0;    
}
