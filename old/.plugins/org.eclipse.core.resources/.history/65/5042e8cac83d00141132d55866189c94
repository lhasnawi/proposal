

package org.omnetpp.queueing;

//
// TODO auto-generated module
//
simple Osource
{

        parameters:
        @group(Queueing);
        @signal[created](type="int");
        @statistic[created](title="Number of Timeslots Created by Source";record=mean;interpolationmode=none);
  		@display("i=block/source,#808000");
        

        
		//int numTimeslotsP = default(4);          		// number of Timeslots
		//int timeslotSizeP @unit(bit) = default (12000bit);   // timeslot size in bits
		//int numFramesP = default(4);               		// number of Frames
		//double dataRateP @unit(bps)= default (10e6bps); // transmission datarate 
		//double guardTimeP @unit(s) = (.001s);
		
        
        
        
       // volatile double interArrivalTimeP @unit(s) = default (1s);// default (1s) ; // time between generated jobs
       double startTime @unit(s) = default(1s); // when the module sends out the first job
       double stopTime @unit(s) = default(-1s); 		// when the module stops the job generation (-1 means no limit)
       int numJobs = default(-1);			//default(-1);// number of jobs to be generated (-1 means no limit)         

    gates:
        inout control;
        output out;
    
        
        
}
