assignment=float(input("Enter grade of assignment "))
if assignment>100 or assignment<0: 
	print("Please enter number between 0-100")
	assignment=float(input("Enter grade of assignment "))
midterm=float(input("Enter grade of midterm "))
if midterm>100 or midterm<0:
	print("Please enter number between 0-100")
	midterm=float(input("Enter grade of midterm "))
tutorial=float(input("Enter grade of tutorial "))
if tutorial>100 or tutorial<0:
	print("Please enter number between 0-100")
	tutorial=float(input("Enter grade of tutorial "))
final_exam=float(input("Enter grade of final exam "))
if final_exam>100 or final_exam<0:
	print("Please enter number between 0-100")
	final_exam=float(input("Enter grade of final exam "))

assignment_grade=((50/100)*assignment)
midterm_grade=((15/100)*midterm)
tutorial_grade=((10/100)*tutorial)
final_exam_grade=((25/100)*final_exam)

final_grade=assignment_grade+ midterm_grade + tutorial_grade + final_exam_grade
print(final_grade)
