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
// TODO auto-generated module
//
simple Osink
{
        parameters:
        @group(Queueing);
        @display("i=block/sink,#808000");
        //@signal[lifeTime](type="simtime_t");
        //@signal[totalQueueingTime](type="simtime_t");
        //@signal[totalDelayTime](type="simtime_t");
        //@signal[totalServiceTime](type="simtime_t");
        //@signal[queuesVisited](type="int");
        //@signal[delaysVisited](type="int");
        //@signal[generation](type="int");
        @signal[arrivedToSink](type="int");
        //@statistic[lifeTime](title="lifetime of arrived jobs";unit=s;record=vector,mean,max;interpolationmode=none);
       // @statistic[totalQueueingTime](title="the total time spent in queues by arrived jobs";unit=s;record=vector?,mean,max;interpolationmode=none);
       // @statistic[totalDelayTime](title="the total time spent in delay nodes by arrived jobs";unit=s;record=vector?,mean,max;interpolationmode=none);
       // @statistic[totalServiceTime](title="the total time spent  by arrived jobs";unit=s;record=vector?,mean,max;interpolationmode=none);
       // @statistic[queuesVisited](title="the total number of queues visited by arrived jobs";record=vector?,mean,max;interpolationmode=none);
       // @statistic[delaysVisited](title="the total number of delays visited by arrived jobs";record=vector?,mean,max;interpolationmode=none);
       // @statistic[generation](title="the generation of the arrived jobs";record=vector?,mean,max;interpolationmode=none);
        @statistic[arrivedToSink](title="Number of Timeslots Arrived to Sink";record=mean;interpolationmode=none);
        bool keepJobs = default(true); // whether to keep the received jobs till the end of simulation
        double timeslotDurationP @unit(s)= default (.001s);
        double guardTimeP @unit(s) = (.001s);
    gates:
        input in[];
        inout control;        
}
