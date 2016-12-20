#!/usr/bin/env python

import rospy
from irpos import *
#from exirpos import *
import numpy as np
from std_msgs.msg import *
from visualization_msgs.msg import Marker
# DEMO FUNCTIONS

# POSTUMENT DEMOS

def synchro_position():

	irpos.move_to_synchro_position(10.0)

	print "Synchro position reached."
	
def get_status():

	print('[Joint position]')
	print str(irpos.get_joint_position())
	print('[Motor position]')
	print str(irpos.get_motor_position())
	print('[Cartesian pose]')
	print str(irpos.get_cartesian_pose())
	print('[Wrench]')
	print str(irpos.get_force_readings())
	print('done')

def top_position():
	joint_trajectory = [JointTrajectoryPoint([0.0,0.0, -1.5707963268, 0.0, 0.0, 4.7123889804 , 0.0], [0.0,0.0, 0.0, 0.0, 0.0, 0.0, 0.0], [], [], rospy.Duration(10.0))]
	irpos.move_along_joint_trajectory(joint_trajectory)
	print('done')

def side_position():

	joint_trajectory = [JointTrajectoryPoint([0.0, 0.0, -np.pi/2, 0.0, np.pi/2, np.pi, 0.0], [0.0,0.0, 0.0, 0.0, 0.0, 0.0, 0.0], [], [], rospy.Duration(10.0))]
	irpos.move_along_joint_trajectory(joint_trajectory)
	#print str(np.pi/2)
	print 'Done'

def front_position():

	joint_trajectory = [JointTrajectoryPoint([0.0, 0.0, -np.pi/2, 0.0, np.pi/2, np.pi/2, -np.pi/2], [0.0,0.0, 0.0, 0.0, 0.0, 0.0, 0.0], [], [], rospy.Duration(10.0))]
	irpos.move_along_joint_trajectory(joint_trajectory)
	#print str(np.pi/2)
	print 'Done'

def check_forces():
	front_position()
	irpos.conmanSwitch(['repoUni'], [], True)
	time.sleep(5.0)
	side_position()
	time.sleep(5.0)
	top_position()
	time.sleep(5.0)
	irpos.conmanSwitch([], ['repoUni'], True)
	synchro_position()
	

#MAIN
irpos = IRPOS("IRpOS", "Irp6ot", 7, "irp6ot_manager")
rviz_pub = rospy.Publisher('visualization_marker', Marker)
marker = Marker()
time.sleep(1.0)

if __name__ == '__main__':
	if sys.argv[1]=="synchPosition":
		synchro_position()	
	elif sys.argv[1]=="topPosition":
		top_position()
	elif sys.argv[1]=="getStatus":
		get_status()	
	elif sys.argv[1]=="sidePosition":
		side_position()
	elif sys.argv[1]=="checkForces":
		check_forces()
	elif sys.argv[1]=="frontPosition":
		front_position()
