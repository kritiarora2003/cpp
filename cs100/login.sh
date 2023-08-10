echo "Enter 1 for Sign up, 2 for Login, 3 for Forgot password"
read num
f=0

if [ $num -eq 1 ]
then
	echo "Enter name"
	read Name
	if [[ $Name =~ ^[A-Z][a-z]+" "[A-Z][a-z]+$ ]] ;
	then 
		echo "valid name"
	else
		echo "Invalid name"
		f=1
	fi
	
	echo "Enter username"
	read user
	if grep -q -o "$user" userinfo.txt
	then 
	echo "user already exists"
	f=1
	else
		if [[ $user =~ ^[a-zA-Z][a-zA-Z0-9]+$ ]] ;
		then 
			echo "valid username"
		else
			echo "Invalid username"
			f=1
		fi
		
		
		echo "Enter email"
		read email
		if [[ $email =~ ^[a-zA-Z][a-zA-Z0-9]+"@"[a-z]+"."[a-z]+"."[a-z]+$ ]] ;
		then 
			echo "valid email"
		else
			echo "Invalid email"
			f=1
		fi

		echo "enter password"
		read password
		if [[ ${#password} -lt 8 || ${#password} -gt 12 ]]; then
		  echo "Invalid password: password should contain 8 to 12 characters"
		  f=1
		elif ! [[ $password =~ [A-Z] ]]; then
		  echo "Invalid password: password should contain at least 1 capital letter"
		  f=1
		elif ! [[ $password =~ [a-z] ]]; then
		  echo "Invalid password: password should contain at least 1 small letter"
		  f=1
		elif ! [[ $password =~ [*@#$%] ]]; then
		  echo "Invalid password: password should contain at least 1 special character (*, @, #, $, %)"
		  f=1
		elif ! [[ $password =~ [0-9] ]]; then
		  echo "Invalid password: password should contain at least 1 digit"
		  f=1
		else
		  echo "Valid password"
		fi

			
		if [ $f -eq 0 ]; then
		echo "$Name,$email,$user,$password" >> userinfo.txt
		echo "sign up successful"
		else
		echo "try again"
		fi
fi
	
elif [ $num -eq 2 ]
then

	echo "username"
	read username 

	if grep -q -o "$username" userinfo.txt 
	then
		echo "pass"
		read pass
		if grep -q "$username,$pass" userinfo.txt 
		then
			echo "welcome"
		else 
			echo "CHOR CHOR CHOR (incorrect password)"
		fi
	else 
		echo "user not found (who are you?)"
	fi
	
elif [ $num -eq 3 ]
then
	echo "enter username"
	read username 

	if grep -q -o "$username" userinfo.txt 
	then
		echo "enter email"
		read email
		if grep -q "$email,$username" userinfo.txt
		then 
			echo "enter new password"
			read pass
			if [[ ${#pass} -lt 8 || ${#pass} -gt 12 ]]; then
				  echo "Invalid password: password should contain 8 to 12 characters"
				elif ! [[ $pass =~ [A-Z] ]]; then
				  echo "Invalid password: password should contain at least 1 capital letter"
				elif ! [[ $pass =~ [a-z] ]]; then
				  echo "Invalid password: password should contain at least 1 small letter"
				elif ! [[ $pass =~ [*@#$%] ]]; then
				  echo "Invalid password: password should contain at least 1 special character (*, @, #, $, %)"
				elif ! [[ $pass =~ [0-9] ]]; then
				  echo "Invalid password: password should contain at least 1 digit"
				else
				  p=`grep "$username" userinfo.txt | cut -d ',' -f4` 
			sed -i "s/$p/$pass/g" userinfo.txt
			echo "ho gaya change"
			fi
			
		else
			echo "Invalid Email"
		fi	
	else
		echo "Invalid username"
	fi
	
fi





















