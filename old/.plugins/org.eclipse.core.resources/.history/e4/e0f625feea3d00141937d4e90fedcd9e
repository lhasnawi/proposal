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
import org.omnetpp.queueing.Osink;
import org.omnetpp.queueing.Source3D;


//
// TODO documentation
//
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
        source3D.out --> osink.in++;
}

