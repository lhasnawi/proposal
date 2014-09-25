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

import ned.IdealChannel;
import org.omnetpp.queueing.ControlChannel;
import org.omnetpp.queueing.P3DController;
import org.omnetpp.queueing.P3DMod;
import org.omnetpp.queueing.P3DSink;
import org.omnetpp.queueing.P3DSource;
import org.omnetpp.queueing.P3DWLC;


//
// TODO auto-generated type
//
network P3DSwitch2222
{
    @display("bgb=547,406;i=block/network;bgi=background/green,t;is=n");
    submodules:
        Source0w0: P3DSource {
            @display("p=67,100");

        }
        p3DSink0: P3DSink {
            @display("p=494,100");
        }
        p3DController: P3DController {
            @display("p=270,32");
        }
        Source1w1: P3DSource {
            @display("p=67,189");
        }
        p3DSink1: P3DSink {
            @display("p=494,189");
        }
        p3DMod: P3DMod {
            @display("p=494,32");
        }
        Source2w0: P3DSource {
            @display("p=67,260");
        }
        Source3w1: P3DSource {
            @display("p=64,350");
        }
        p3DSink2: P3DSink {
            @display("p=494,260");
        }
        p3DSink3: P3DSink {
            @display("p=494,350");
        }
        WLC01: P3DWLC {
            @display("p=280,100");
        }
        WLC10: P3DWLC {
            @display("p=280,189");
        }
        WLC01_2: P3DWLC {
            @display("p=280,260");
        }
        WLC10_2: P3DWLC {
            @display("p=280,350");
        }
    connections:
        p3DController.control++ <--> ControlChannel <--> Source0w0.control;
        p3DController.control++ <--> ControlChannel <--> p3DSink0.control;
        p3DController.control++ <--> ControlChannel <--> Source1w1.control;
        p3DController.control++ <--> ControlChannel <--> p3DSink1.control;
        p3DController.modDB <--> ControlChannel <--> p3DMod.control;
        Source2w0.control <--> ControlChannel <--> p3DController.control++;
        Source3w1.control <--> ControlChannel <--> p3DController.control++;
        p3DSink2.control <--> ControlChannel <--> p3DController.control++;
        p3DSink3.control <--> ControlChannel <--> p3DController.control++;
        Source0w0.dataOut --> IdealChannel --> WLC01.dataIn;
        WLC01.dataOut --> IdealChannel --> p3DSink1.dataIn;
        Source1w1.dataOut --> IdealChannel --> WLC10.dataIn;
        WLC10.dataOut --> IdealChannel --> p3DSink0.dataIn;
        Source2w0.dataOut --> IdealChannel --> WLC01_2.dataIn;
        WLC01_2.dataOut --> IdealChannel --> p3DSink3.dataIn;
        Source3w1.dataOut --> IdealChannel --> WLC10_2.dataIn;
        WLC10_2.dataOut --> IdealChannel --> p3DSink2.dataIn;
}
