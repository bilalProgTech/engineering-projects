<?php
   define('DB_SERVER', 'localhost');
   define('DB_USERNAME', '');
   define('DB_PASSWORD', '');
   define('DB_DATABASE', '');
   $db = mysqli_connect(DB_SERVER,DB_USERNAME,DB_PASSWORD,DB_DATABASE);
   session_start();
   
   if($_SERVER["REQUEST_METHOD"] == "POST") 
{
      // username and password sent from form 
      
      $myusername = mysqli_real_escape_string($db,$_POST['username']);
      $mypassword = mysqli_real_escape_string($db,$_POST['password']);
	$_SESSION['user'] = $username;
      $sql = "SELECT un FROM login WHERE un = '$myusername' and pw = '$mypassword'";
      $result = mysqli_query($db,$sql);      
      $count = mysqli_num_rows($result);


      
      
      // If result matched $myusername and $mypassword, table row must be 1 row
      if($count == 1) 
      {
	if($myusername=='admin')
		{
			
			header('location: updatedata.php');
		}

	if($myusername=='rash')
		{	
			header("location: forms.php");
		}
	}


      else 
      {
         echo $error = "Your Login Name or Password is invalid";
      }
   	} 
?>
<html>
   
   <head>
      <title>Login Page</title>
      
      <style type = "text/css">

         hr{
            border: 0.1px solid steelblue;
         }


         header{
            background:steelblue;
         }

         fieldset{
            background-color: steelblue;
         }
         body {
            font-family:Arial, Helvetica, sans-serif;
            font-size:14px;
         }
         
         label {
            font-weight:bold;
            width:100px;
            font-size:14px;
         }
         
         .box {
            border:#666666 solid 1px;
         }
      </style>
      
   </head>
   
   <body bgcolor = "#FFFFFF">
   <fieldset>
   <header>
   <table align="center">
      <tr>
         <td><img src="dbit.png" alt="DBIT LOGO" style="width: 75px;height: 75px;"></td>
         <td><font size="6" color="white">DON BOSCO INSTITUTE OF TECHNOLOGY</font><br>
         </td>
      </tr>
   </table>
</header>
</fieldset>
<hr>	
<br><br>
      <div align = "center">
         <div style = "width:300px; border: solid 1px #333333; " align = "left">
            <div style = "background-color:steelblue; color:#FFFFFF; padding:3px;"><b>Login</b></div>
				
            <div style = "margin:30px">
               
               <form action = "" method = "post">
               <table>
               <tr>
                  <td><label>UserName  :</label><input type = "text" name = "username" class = "box"/><br /><br /></td></tr>
                 <tr><td><label>Password  :</label><input type = "password" name = "password" class = "box" /><br/><br /></td>
                 </tr>
                 </table>
                  <input type = "submit" value = " Submit "/><br />
               </form>
               
               <div style = "font-size:11px; color:#cc0000; margin-top:10px"></div>
            
					
            </div>
				
         </div>
			
      </div>

<br><br>

      <form action="index.php" name="back">

      <center><input type="submit" value="Back To Homepage"/></center>

      </form>

   </body>
</html>

