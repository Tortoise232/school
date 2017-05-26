<?xml version="1.0"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">

<html>
	<body>
		<h2>Programmer Cookbook</h2>
		<table border="1">
			<xsl:for-each select="recipes/recipe">
			<xsl:sort select = "preptime" order = "descending" data-type="number"/> 
			<xsl:sort select = "cooktime" order = "descending" data-type="number"/>
			<tr>
			    <td><xsl:value-of select="name"/></td>
				<td><xsl:value-of select="ingredients"/></td>
				<td><xsl:value-of select="preptime"/></td>
				<td><xsl:value-of select="cooktime"/></td>
				<td><xsl:value-of select="steps"/></td>
			</tr>
			</xsl:for-each>
		</table>
	</body>
</html>

</xsl:template>
</xsl:stylesheet>
