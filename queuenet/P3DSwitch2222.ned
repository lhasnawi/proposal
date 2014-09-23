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
import org.omnetpp.queueing.Controller3D;
import org.omnetpp.queueing.P3DController;
import org.omnetpp.queueing.P3DSink;
import org.omnetpp.queueing.P3DSource;


//
// TODO auto-generated type
//
network P3DSwitch2222
{
    @display("bgb=547,179;i=block/network;bgi=background/green,t;is=n");
    submodules:
        p3DSource: P3DSource {
            @display("p=67,100");
        }
        p3DSink: P3DSink {
            @display("p=494,100");
        }
        p3DController: P3DController {
            @display("p=279,20");
        }
    connections:
        p3DSource.dataOut --> IdealChannel --> p3DSink.dataIn;
        p3DController.control++ <--> ControlChannel <--> p3DSource.control;
        p3DController.control++ <--> ControlChannel <--> p3DSink.control;
}