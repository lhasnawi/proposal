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
//
// TODO documentation
//
import ned.IdealChannel;
import org.omnetpp.queueing.ControlChannel;
import org.omnetpp.queueing.P3DController;
import org.omnetpp.queueing.P3DMod;
import org.omnetpp.queueing.P3DSink;
import org.omnetpp.queueing.P3DSource;
import org.omnetpp.queueing.P3DWLC;


network P3DSwitch
{
    @display("bgb=1044,453");
    submodules:
        Source0w0: P3DSource {
            @display("p=67,100");

        }
        p3DSink0: P3DSink {
            @display("p=938,100");
        }
        p3DController: P3DController {
            @display("p=521,32");
        }
        Source1w1: P3DSource {
            @display("p=67,189");
        }
        p3DSink1: P3DSink {
            @display("p=938,189");
        }
        p3DMod: P3DMod {
            @display("p=838,24");
        }
        Source2w0: P3DSource {
            @display("p=67,260");
        }
        Source3w1: P3DSource {
            @display("p=64,350");
        }
        p3DSink2: P3DSink {
            @display("p=938,260");
        }
        p3DSink3: P3DSink {
            @display("p=938,350");
        }
        WLC01: P3DWLC {
            @display("p=352,211");
        }
        WLC10: P3DWLC {
            @display("p=404,213");
        }
        WLC01_2: P3DWLC {
            @display("p=602,211");
        }
        WLC10_2: P3DWLC {
            @display("p=665,211");
        }
        Switch0_w0: org.omnetpp.queueing.P3DSwitch {
            @display("p=287,100");
        }
        Switch1_w1: org.omnetpp.queueing.P3DSwitch {
            @display("p=273,350");
        }
        Switch4_w0: org.omnetpp.queueing.P3DSwitch {
            @display("p=766,100");
        }
        Switch5_w1: org.omnetpp.queueing.P3DSwitch {
            @display("p=766,350");
        }
        Switch2_w0: org.omnetpp.queueing.P3DSwitch {
            @display("p=486,100");
        }
        Switch3_w1: org.omnetpp.queueing.P3DSwitch {
            @display("p=486,350");
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
        Source0w0.dataOut --> IdealChannel --> Switch0_w0.dataIn[0];
        Source2w0.dataOut --> IdealChannel --> Switch0_w0.dataIn[1];
        Source1w1.dataOut --> IdealChannel --> Switch1_w1.dataIn[0];
        Source3w1.dataOut --> IdealChannel --> Switch1_w1.dataIn[1];
        Switch4_w0.dataOut[0] --> IdealChannel --> p3DSink0.dataIn;
        Switch4_w0.dataOut[1] --> IdealChannel --> p3DSink1.dataIn;
        Switch5_w1.dataOut[0] --> IdealChannel --> p3DSink2.dataIn;
        Switch5_w1.dataOut[1] --> IdealChannel --> p3DSink3.dataIn;
        Switch0_w0.dataOut[0] --> IdealChannel --> Switch2_w0.dataIn[0];
        Switch0_w0.dataOut[1] --> IdealChannel --> WLC01.dataIn;
        Switch1_w1.dataOut[0] --> IdealChannel --> Switch3_w1.dataIn[0];
        Switch1_w1.dataOut[1] --> IdealChannel --> WLC10.dataIn;
        WLC01.dataOut --> IdealChannel --> Switch3_w1.dataIn[1];
        WLC10.dataOut --> IdealChannel --> Switch2_w0.dataIn[1];
        Switch2_w0.dataOut[0] --> IdealChannel --> Switch4_w0.dataIn[0];
        Switch3_w1.dataOut[0] --> IdealChannel --> Switch5_w1.dataIn[0];
        Switch2_w0.dataOut[1] --> IdealChannel --> WLC01_2.dataIn;
        Switch3_w1.dataOut[1] --> IdealChannel --> WLC10_2.dataIn;
        WLC01_2.dataOut --> IdealChannel --> Switch5_w1.dataIn[1];
        WLC10_2.dataOut --> IdealChannel --> Switch4_w0.dataIn[1];
}

