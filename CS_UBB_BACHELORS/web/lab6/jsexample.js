<form>
<p>This widget uses javascript to transform this:</p>
<table border="0">
	<tr>
		<td>Where do you come from?</td>
		<td><input type="text" name="myText_ex" value="Norway" selectBoxOptions="Canada;Denmark;Finland;Germany;Mexico;Norway;Sweden;United Kingdom;United States"></td>
	</tr>
	<tr>
		<td>What is your name?</td>
		<td><input type="text" name="myText_ex2" value="" selectBoxOptions="Amy;Andrew;Carol;Jennifer;Jim;Tim;Tommy;Vince"></td>
	</tr>
</table>
<p>Into this:</p>
<table border="0">
	<tr>
		<td>Where do you come from?</td>
		<td><input type="text" name="myText" value="Norway" selectBoxOptions="Canada;Denmark;Finland;Germany;Mexico;Norway;Sweden;United Kingdom;United States"></td>
	</tr>
	<tr>
		<td>What is your name?</td>
		<td><input type="text" name="myText2" value="" selectBoxOptions="Amy;Andrew;Carol;Jennifer;Jim;Tim;Tommy;Vince"></td>
	</tr>
</table>
<p>I.e.: A combination of text- and selectbox. You can type in a value or choose from the list</p>
</form>

<script type="text/javascript">
createEditableSelect(document.forms[0].myText);
createEditableSelect(document.forms[0].myText2);
</script>
