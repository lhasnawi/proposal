//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package org.omnetpp.queueing;

//
// TODO auto-generated type
//
simple Ocontroller
{
 		@display("i=device/router,#808000");

        @group(Queueing);
    
		
		int numTimeslotsP; // = default(4);          		// number of Timeslots
		int timeslotSizeP @unit(bit); //= default (1000000bit);   // timeslot size in bits 1Mbit
		int numFramesP; // = default(4);               		// number of Frames
		double dataRateP @unit(bps); //= default (10e6bps); // transmission datarate 
		int caseIndex;
		int switchingAssignment; //= default(0);
		int switchingAssignmentOdd;
		int switchingAssignmentEven;
		//int numJobs = default(-1);			//default(-1);// number of jobs to be generated (-1 means no limit)         
		
		
        
        
    	    gates:

        inout control[];

}
