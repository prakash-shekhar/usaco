
# NAMES				: Owen Su, Prakash Shekhar
# GROUP				: DM
# DATE				: OCT 4th
# PROBLEM NAME		: COMCON OCT 2007 P2


f = open("PROGRAM1.DAT", "r")

nameDict={'JANUARY':1, 'FEBRUARY':2, 'MARCH':3, 'APRIL':4, 'MAY':5, 'JUNE':6, 'JULY':7, 'AUGUST':8, 'SEPTEMBER':9, 'OCTOBER':10, 'NOVEMBER':11, 'DECEMBER':12}
monthDict={1:'JANUARY', 2:'FEBRUARY', 3:'MARCH', 4:'APRIL', 5:'MAY', 6:'JUNE', 7:'JULY', 8:'AUGUST', 9:'SEPTEMBER', 10:'OCTOBER', 11:'NOVEMBER', 12:'DECEMBER'}

shortnameDict ={'JAN':1, 'FEB':2, 'MAR':3, 'APR':4, 'MAY':5, 'JUN':6, 'JUL':7, 'AUG':8, 'SEP':9, 'OCT':10, 'NOV':11, 'DEC':12}
shortmonthDict={1:'JAN', 2:'FEB', 3:'MAR', 4:'APR', 5:'MAY', 6:'JUN', 7:'JUL', 8:'AUG', 9:'SEP', 10:'OCT', 11:'NOV', 12:'DEC'}


print("Owen Su, Prakash Shekhar\nDM\nCOMCON OCT 2007 P1")

for i in range(5):
	s = f.readline().strip('\n')
	toconv = -1
	if s[-8:] == "MM-DD-YY":
		toconv = 0
		s = s[:-8]
	elif s[-9:] == "DD-MMM-YY":
		toconv = 1
		s = s[:-9]
	elif s[-14:] == "MONTH DAY YEAR":
		toconv = 2
		s = s[:-14]
	monthstr = ''
	daystr = ''
	yearstr = ''
	# if MONTH
	print()
	if s[0].isalpha() and toconv == 2:
		print(s)
		break;
	if s[0].isalpha():
		s = s.split(' ')
		month = nameDict[s[0]]
		if(month<10):
			monthstr += '0'
		monthstr += str(month)
		day = s[1][:-1]
		if(int(day)<10):
			daystr += '0'
		daystr += str(day)
		year = s[2]
		yearstr = year[-2:]
		print(monthstr+"-"+daystr+"-"+yearstr)