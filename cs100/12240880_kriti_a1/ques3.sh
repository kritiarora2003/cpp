echo "Welcome"
echo "Press 1 to sign up"
echo "Press 2 to log in"
echo "Press 3 to reset password"

read choice
flag=0

if [ $choice -eq 1 ]
then
	echo "Enter name"
	read name
	if [[ $name =~ ^[A-Z][a-z]+" "[A-Z][a-z]+$ ]] ;
	then 
		echo "Valid name :)"
	else
		echo "Invalid name, please try again"
		flag=1
		exit 1
	fi
	
	echo "Enter username"
	read user
	if grep -q -o "$user" userinfo.txt
	then 
	echo "Username already exists, please try again"
	flag=1
	exit 1
	else
		if [[ $user =~ ^[a-zA-Z][a-zA-Z0-9]+$ ]] ;
		then 
			echo "Valid username :)"
		else
			echo "Invalid username, please try again"
			flag=1
			exit 1
		fi
		
		
		echo "Enter email"
		read email
		if [[ $email =~ ^[a-zA-Z][a-zA-Z0-9]+"@"[a-z]+"."[a-z]+"."[a-z]+$ ]] ;
		then 
			echo "Valid email :)"
		else
			echo "Invalid email, please try again"
			flag=1
			exit 1
		fi

		echo "Enter password"
		read password
		if [[ ${#password} -lt 8 || ${#password} -gt 12 ]]; then
		  echo "Invalid password: character limit incorrect"
		  flag=1
		  exit 1
		elif ! [[ $password =~ [A-Z] ]]; then
		  echo "Invalid password: password should contain at least 1 capital letter"
		  flag=1
		  exit 1
		elif ! [[ $password =~ [a-z] ]]; then
		  echo "Invalid password: password should contain at least 1 small letter"
		  flag=1
		  exit 1
		elif ! [[ $password =~ [*@#$%] ]]; then
		  echo "Invalid password: password should contain at least 1 special character (*, @, #, $, %)"
		  flag=1
		  exit 1
		elif ! [[ $password =~ [0-9] ]]; then
		  echo "Invalid password: password should contain at least 1 digit"
		  flag=1
		  exit 1
		else
		  echo "Valid password :)"
		fi

			
		if [ $f -eq 0 ]; then
		echo "$Name,$email,$user,$password" >> userinfo.txt
		echo "Your sign up was completed successfully, now please login :)"
		else
		echo "Try again :("
		fi
fi
	
elif [ $choice -eq 2 ]
then

	echo "username"
	read username 

	if grep -q -o "$username" userinfo.txt 
	then
		echo "pass"
		read pass
		if grep -q "$username,$pass" userinfo.txt 
		then
			echo "Login successful"
		else 
			echo "Incorrect password, please try again"
		fi
	else 
		echo "User not found, either check username or sign up"
	fi
	
elif [ $choice -eq 3 ]
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
			echo "Password changed successful"
			fi
			
		else
			echo "Invalid Email"
		fi	
	else
		echo "Invalid username"
	fi
	
fi





















