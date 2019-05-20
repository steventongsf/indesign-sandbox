<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.1">
	<xsl:output method="xml" indent="yes"/>
	<xsl:template match="/package/graphics">
		<xsl:document href="{$workingdir}{$filesep}Resources{$filesep}Graphic.xml" method="xml" indent="yes">
			<idPkg:Graphic xmlns:idPkg="http://ns.adobe.com/AdobeInDesign/idml/1.0/packaging" DOMVersion="7.5">
				<Color Self="Color/Black" Model="Process" Space="CMYK" ColorValue="0 0 0 100" ColorOverride="Specialblack" AlternateSpace="NoAlternateColor" AlternateColorValue="" Name="Black" ColorEditable="false" ColorRemovable="false" Visible="true" SwatchCreatorID="7937"/>
				<Color Self="Color/C=0 M=0 Y=100 K=0" Model="Process" Space="CMYK" ColorValue="0 0 100 0" ColorOverride="Normal" AlternateSpace="NoAlternateColor" AlternateColorValue="" Name="C=0 M=0 Y=100 K=0" ColorEditable="true" ColorRemovable="true" Visible="true" SwatchCreatorID="7937"/>
				<Color Self="Color/C=0 M=100 Y=0 K=0" Model="Process" Space="CMYK" ColorValue="0 100 0 0" ColorOverride="Normal" AlternateSpace="NoAlternateColor" AlternateColorValue="" Name="C=0 M=100 Y=0 K=0" ColorEditable="true" ColorRemovable="true" Visible="true" SwatchCreatorID="7937"/>
				<Color Self="Color/C=100 M=0 Y=0 K=0" Model="Process" Space="CMYK" ColorValue="100 0 0 0" ColorOverride="Normal" AlternateSpace="NoAlternateColor" AlternateColorValue="" Name="C=100 M=0 Y=0 K=0" ColorEditable="true" ColorRemovable="true" Visible="true" SwatchCreatorID="7937"/>
				<Color Self="Color/C=100 M=90 Y=10 K=0" Model="Process" Space="CMYK" ColorValue="100 90 10 0" ColorOverride="Normal" AlternateSpace="NoAlternateColor" AlternateColorValue="" Name="C=100 M=90 Y=10 K=0" ColorEditable="true" ColorRemovable="true" Visible="true" SwatchCreatorID="7937"/>
				<Color Self="Color/C=15 M=100 Y=100 K=0" Model="Process" Space="CMYK" ColorValue="15 100 100 0" ColorOverride="Normal" AlternateSpace="NoAlternateColor" AlternateColorValue="" Name="C=15 M=100 Y=100 K=0" ColorEditable="true" ColorRemovable="true" Visible="true" SwatchCreatorID="7937"/>
				<Color Self="Color/C=75 M=5 Y=100 K=0" Model="Process" Space="CMYK" ColorValue="75 5 100 0" ColorOverride="Normal" AlternateSpace="NoAlternateColor" AlternateColorValue="" Name="C=75 M=5 Y=100 K=0" ColorEditable="true" ColorRemovable="true" Visible="true" SwatchCreatorID="7937"/>
				<Color Self="Color/Cyan" Model="Process" Space="CMYK" ColorValue="100 0 0 0" ColorOverride="Hiddenreserved" AlternateSpace="NoAlternateColor" AlternateColorValue="" Name="Cyan" ColorEditable="false" ColorRemovable="false" Visible="false" SwatchCreatorID="7937"/>
				<Color Self="Color/Magenta" Model="Process" Space="CMYK" ColorValue="0 100 0 0" ColorOverride="Hiddenreserved" AlternateSpace="NoAlternateColor" AlternateColorValue="" Name="Magenta" ColorEditable="false" ColorRemovable="false" Visible="false" SwatchCreatorID="7937"/>
				<Color Self="Color/Paper" Model="Process" Space="CMYK" ColorValue="0 0 0 0" ColorOverride="Specialpaper" AlternateSpace="NoAlternateColor" AlternateColorValue="" Name="Paper" ColorEditable="true" ColorRemovable="false" Visible="true" SwatchCreatorID="7937"/>
				<Color Self="Color/Registration" Model="Registration" Space="CMYK" ColorValue="100 100 100 100" ColorOverride="Specialregistration" AlternateSpace="NoAlternateColor" AlternateColorValue="" Name="Registration" ColorEditable="false" ColorRemovable="false" Visible="true" SwatchCreatorID="7937"/>
				<Color Self="Color/Yellow" Model="Process" Space="CMYK" ColorValue="0 0 100 0" ColorOverride="Hiddenreserved" AlternateSpace="NoAlternateColor" AlternateColorValue="" Name="Yellow" ColorEditable="false" ColorRemovable="false" Visible="false" SwatchCreatorID="7937"/>
				<Color Self="Color\u80" Model="Process" Space="CMYK" ColorValue="0 0 0 100" ColorOverride="Normal" AlternateSpace="NoAlternateColor" AlternateColorValue="" Name="$ID/" ColorEditable="true" ColorRemovable="true" Visible="false" SwatchCreatorID="7937"/>
				<Color Self="Color\u82" Model="Process" Space="CMYK" ColorValue="0 0 0 0" ColorOverride="Normal" AlternateSpace="NoAlternateColor" AlternateColorValue="" Name="$ID/" ColorEditable="true" ColorRemovable="true" Visible="false" SwatchCreatorID="7937"/>
				<Ink Self="Ink/$ID/Process Cyan" Name="$ID/Process Cyan" AliasInkName="k[NoAlias]" Angle="15" ConvertToProcess="false" Frequency="60" NeutralDensity="0.61" PrintInk="true" TrapOrder="1" InkType="Normal"/>
				<Ink Self="Ink/$ID/Process Magenta" Name="$ID/Process Magenta" AliasInkName="k[NoAlias]" Angle="75" ConvertToProcess="false" Frequency="60" NeutralDensity="0.76" PrintInk="true" TrapOrder="2" InkType="Normal"/>
				<Ink Self="Ink/$ID/Process Yellow" Name="$ID/Process Yellow" AliasInkName="k[NoAlias]" Angle="0" ConvertToProcess="false" Frequency="60" NeutralDensity="0.16" PrintInk="true" TrapOrder="3" InkType="Normal"/>
				<Ink Self="Ink/$ID/Process Black" Name="$ID/Process Black" AliasInkName="k[NoAlias]" Angle="45" ConvertToProcess="false" Frequency="60" NeutralDensity="1.7" PrintInk="true" TrapOrder="4" InkType="Normal"/>
				<PastedSmoothShade Self="PastedSmoothShade\u83" ContentsVersion="0" ContentsType="ConstantShade" SpotColorList="" ContentsEncoding="Ascii64Encoding" ContentsMatrix="1 0 0 1 0 0" Name="$ID/" ColorEditable="true" ColorRemovable="true" Visible="false" SwatchCreatorID="7937">
					<Properties>
						<Contents><![CDATA[AAAAAUBv4AAAAAAAAAAAAAAAAAAAAAAAAAAAAA==]]></Contents>
					</Properties>
				</PastedSmoothShade>
				<Swatch Self="Swatch/None" Name="None" ColorEditable="false" ColorRemovable="false" Visible="true" SwatchCreatorID="7937"/>
				<Gradient Self="Gradient\u81" Type="Linear" Name="$ID/" ColorEditable="true" ColorRemovable="true" Visible="false" SwatchCreatorID="7937">
					<GradientStop Self="u81GradientStop0" StopColor="Color\u82" Location="0"/>
					<GradientStop Self="u81GradientStop1" StopColor="Color/Black" Location="100" Midpoint="50"/>
				</Gradient>
				<StrokeStyle Self="StrokeStyle/$ID/Triple_Stroke" Name="$ID/Triple_Stroke"/>
				<StrokeStyle Self="StrokeStyle/$ID/ThickThinThick" Name="$ID/ThickThinThick"/>
				<StrokeStyle Self="StrokeStyle/$ID/ThinThickThin" Name="$ID/ThinThickThin"/>
				<StrokeStyle Self="StrokeStyle/$ID/ThickThick" Name="$ID/ThickThick"/>
				<StrokeStyle Self="StrokeStyle/$ID/ThickThin" Name="$ID/ThickThin"/>
				<StrokeStyle Self="StrokeStyle/$ID/ThinThick" Name="$ID/ThinThick"/>
				<StrokeStyle Self="StrokeStyle/$ID/ThinThin" Name="$ID/ThinThin"/>
				<StrokeStyle Self="StrokeStyle/$ID/Japanese Dots" Name="$ID/Japanese Dots"/>
				<StrokeStyle Self="StrokeStyle/$ID/White Diamond" Name="$ID/White Diamond"/>
				<StrokeStyle Self="StrokeStyle/$ID/Left Slant Hash" Name="$ID/Left Slant Hash"/>
				<StrokeStyle Self="StrokeStyle/$ID/Right Slant Hash" Name="$ID/Right Slant Hash"/>
				<StrokeStyle Self="StrokeStyle/$ID/Straight Hash" Name="$ID/Straight Hash"/>
				<StrokeStyle Self="StrokeStyle/$ID/Wavy" Name="$ID/Wavy"/>
				<StrokeStyle Self="StrokeStyle/$ID/Canned Dotted" Name="$ID/Canned Dotted"/>
				<StrokeStyle Self="StrokeStyle/$ID/Canned Dashed 3x2" Name="$ID/Canned Dashed 3x2"/>
				<StrokeStyle Self="StrokeStyle/$ID/Canned Dashed 4x4" Name="$ID/Canned Dashed 4x4"/>
				<StrokeStyle Self="StrokeStyle/$ID/Dashed" Name="$ID/Dashed"/>
				<StrokeStyle Self="StrokeStyle/$ID/Solid" Name="$ID/Solid"/>
			</idPkg:Graphic>
		</xsl:document>
	</xsl:template>
</xsl:stylesheet>
