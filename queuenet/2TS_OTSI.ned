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

import org.omnetpp.queueing.ControlChannel;
import org.omnetpp.queueing.OFDL;
import org.omnetpp.queueing.Ocombiner;
import org.omnetpp.queueing.Ocontroller;
import org.omnetpp.queueing.Osink;
import org.omnetpp.queueing.Osource;
import org.omnetpp.queueing.Osplitter;
import org.omnetpp.queueing.Oswitch;

// added this line to test the work computer
//hello

network _2TS_OTSI
{
    @display("bgb=976,482");
    submodules:
        osource: Osource {
            @display("p=41,370");
        }
        osink: Osink {
            @display("p=884,370");
        }
        osplitter0: Osplitter {
            @display("p=136,370");
        }
        osplitter11: Osplitter {
            @display("p=247,299");
        }
        osplitter21: Osplitter {
            @display("p=247,434");
        }
        oswitch: Oswitch {
            @display("p=406,299");
        }
        oswitch1: Oswitch {
            @display("p=406,434");
        }
        ocombiner11: Ocombiner {
            @display("p=674,299");
        }
        ocombiner21: Ocombiner {
            @display("p=681,434");
        }
        ocombiner0: Ocombiner {
            @display("p=785,370");
        }
        ofdl11: OFDL {
            @display("p=324,227");
        }
        ofdl12: OFDL {
            @display("p=495,227");
        }
        ofdl21: OFDL {
            @display("p=324,370");
        }
        ofdl22: OFDL {
            @display("p=495,370");
        }
        ofdl13: OFDL {
            @display("p=583,227");
        }
        ofdl23: OFDL {
            @display("p=583,370");
        }
        ocontroller: Ocontroller {
            @display("p=447,52");
        }
    connections:
        osource.out --> osplitter0.in;
        osplitter0.out[0] --> osplitter11.in;
        osplitter0.out[1] --> osplitter21.in;
        osplitter11.out[0] --> ofdl11.in;
        osplitter21.out[0] --> ofdl21.in;
        ofdl11.out --> oswitch.in[0];
        ofdl21.out --> oswitch1.in[0];
        oswitch.out[0] --> ofdl12.in;
        oswitch1.out[0] --> ofdl22.in;
        ocombiner11.out --> ocombiner0.in[0];
        ocombiner0.out --> osink.in++;
        osplitter11.out[1] --> oswitch.in[1];
        osplitter21.out[1] --> oswitch1.in[1];
        oswitch.out[1] --> ocombiner11.in[1];
        oswitch1.out[1] --> ocombiner21.in[1];
        ocombiner21.out --> ocombiner0.in[1];
        ofdl12.out --> ofdl13.in;
        ofdl22.out --> ofdl23.in;
        ofdl13.out --> ocombiner11.in[0];
        ofdl23.out --> ocombiner21.in[0];

        ocontroller.control++ <--> ControlChannel <--> osource.control;
        ocontroller.control++ <--> ControlChannel <--> ofdl11.control;
        ocontroller.control++ <--> ControlChannel <--> ofdl12.control;
        ocontroller.control++ <--> ControlChannel <--> ofdl13.control;
        ocontroller.control++ <--> ControlChannel <--> ocombiner11.control;
        ocontroller.control++ <--> ControlChannel <--> oswitch.control;
        ocontroller.control++ <--> ControlChannel <--> osplitter11.control;
        ocontroller.control++ <--> ControlChannel <--> osplitter0.control;
        ocontroller.control++ <--> ControlChannel <--> ofdl21.control;
        ocontroller.control++ <--> ControlChannel <--> ofdl22.control;
        ocontroller.control++ <--> ControlChannel <--> ofdl23.control;
        ocontroller.control++ <--> ControlChannel <--> ocombiner0.control;
        ocontroller.control++ <--> ControlChannel <--> osink.control;
        ocontroller.control++ <--> ControlChannel <--> ocombiner21.control;
        ocontroller.control++ <--> ControlChannel <--> oswitch1.control;
        ocontroller.control++ <--> ControlChannel <--> osplitter21.control;
}
