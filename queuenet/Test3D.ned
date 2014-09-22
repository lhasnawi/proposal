
import ned.DelayChannel;


import org.omnetpp.queueing.Controller3D;
import org.omnetpp.queueing.Switch3D;

import org.omnetpp.queueing.Osink;
import org.omnetpp.queueing.Source3D;





network Network
{
    @display("bgb=503,312");
    submodules:
        source3D: Source3D {
            @display("p=63,103");
        }
        osink: Osink {
            @display("p=293,116");
        }
    connections:
        source3D.out --> DelayChannel {  delay = 1s; } --> osink.in++;

}

