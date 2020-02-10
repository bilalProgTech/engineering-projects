
<!DOCTYPE html>
<html>
<head>
<style>
.division {
	border-radius: 5px;
	background-color: #f2f2f2;
	padding: 20px;
	width: 70%;
	margin-left: auto;
	margin-right: auto;
}
input[type=text]
{
	width: 100%;
	padding: 12px 20px;
	margin: 8px 0;
	display: inline-block;
	border: 1px solid #ccc;
	border-radius: 4px;
	box-sizing: border-box;
}
input[type=submit],button
{ 
	width: 100%;
	background-color: #909497;
	color: black;
	padding: 14px 20px;
	margin: 8px 0;
	border: none;
	border-radius: 4px;
	cursor: pointer;
}
input[type=submit]:hover 
{
	background-color: #626567;
}
table 
{
    font-family: "Courier New",sans-serif;
    border-collapse: collapse;
    width: 100%;
}

td, th 
{
    border: 1px solid #000000;
    text-align: left;
    padding: 8px;
}
th
{
	text-align: center;
}
tr:nth-child(even) 
{
    background-color: #dddddd;
}
</style>
</head>
<body>
<?php
	session_start();
if(isset($_SESSION['user'])){
	echo "Session timed out";     
   }
?>
<p style="text-align: left"><a href="forms.php">Insert |</a>
<a href="updatedata.php">UpDel |</a><a href="logout.php">Logout</a></p>
<br>
<div class="division">
<h1>slides</h1>
<table>
	  	<tr>
	  		<th>name</th>
		</tr>
<?php
   include "database.php";
   
   $sql = 'select name from slides';
   
   $retval = mysql_query( $sql, $conn );
   
   if(! $retval ) {
      die('Could not get data: ' . mysql_error());
   }
   
   while($row = mysql_fetch_assoc($retval)) 
   {
  	echo "<tr>";
  	echo "<td>" . $row['name'] . "</td>";
  	echo "</tr>";
   }
   mysql_free_result($retval);
   
   mysql_close($conn);   
?>
	  </table>
</div>
<br>
<div class="division">
<h1>newsfeed</h1>
<table>
	  	<tr>
	  		<th>name</th>
			<th>nid</th>
		</tr>
<?php
   include "database.php";
   
   $sql = 'select name,nid from newsfeed';
   
   $retval = mysql_query( $sql, $conn );
   
   if(! $retval ) {
      die('Could not get data: ' . mysql_error());
   }
   
   while($row = mysql_fetch_assoc($retval)) 
   {
  	echo "<tr>";
  	echo "<td>" . $row['name'] . "</td>";
  	echo "<td>" . $row['nid'] . "</td>";
  	echo "</tr>";
   }
   mysql_free_result($retval);
   
   mysql_close($conn);   
?>
	  </table>
</div>

<br>
<div class="division">
<h1>csiwork</h1>
<table>
	  	<tr>
	  		<th>name</th>
			<th>cid</th>
		</tr>
<?php
   include "database.php";
   
   $sql = 'select name,cid from csiwork';
   
   $retval = mysql_query( $sql, $conn );
   
   if(! $retval ) {
      die('Could not get data: ' . mysql_error());
   }
   
   while($row = mysql_fetch_assoc($retval)) 
   {
  	echo "<tr>";
  	echo "<td>" . $row['name'] . "</td>";
  	echo "<td>" . $row['cid'] . "</td>";
  	echo "</tr>";
   }
   mysql_free_result($retval);
   
   mysql_close($conn);   
?>
	  </table>
</div>
<br>
<div class="division">
<h1>Write Query here</h1>
<form action="updel.php" method="post" enctype="multipart/form-data"> 
 <input type="text" name="name" >
 <input type="submit" value="Store">
</form>
</div>
</body>
</html>

