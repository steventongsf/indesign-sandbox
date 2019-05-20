<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.1">
<xsl:import href="global-variables.xsl"/>
<xsl:import href="standard-adobe-header.xsl"/>
<xsl:import href="standard-footer.xsl"/>

<xsl:output name="cppfile" method="text"/>
<xsl:template match="triggerresourcedeps-file">Generating TriggerResourceDeps.cpp from template...
<xsl:document href="{/code/@source-dir-absolute}{$filesep}TriggerResourceDeps.cpp" format="cppfile">
<xsl:call-template name="standard-adobe-header"/>
<xsl:call-template name="triggerresourcedeps"/>
<xsl:call-template name="standard-footer"/>
</xsl:document>
</xsl:template>

<xsl:template match="triggerresourcedeps" name="triggerresourcedeps">
#include "<xsl:value-of select="/code/@short-name"/>.fr"
</xsl:template>
</xsl:stylesheet>

