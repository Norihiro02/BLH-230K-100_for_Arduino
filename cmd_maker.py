import serial
def setPoseCmd(deg):
	cmd=[0];
	txlist=[];
	if(deg<0):
		cmd[0]='-';
		deg=deg*-1;
	else:
		cmd[0]='+';
	numlist=list(str(deg))
	for i in range(0,3-len(numlist)):
		numlist.insert(0,'0');
	txlist=cmd+numlist;

	cmdTxlist="";
	for i in txlist:
		cmdTxlist+=i
	return cmdTxlist;

def sendPose(deg):
	ser = serial.Serial('/dev/ttyACM0', 9600);
	cmd=setPoseCmd(deg);
	print "open_serial"
	ser.write(cmd.encode("UTF-8"));
	line = ser.readline();
	line.strip('\n');
	ser.close();
	return int(line);



if __name__=='__main__':
	print sendPose(90);

