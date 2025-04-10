<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet 
    version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <!-- Define output as HTML -->
  <xsl:output method="html" encoding="UTF-8" indent="yes"/>
  
  <!-- The main template matches the CUnit report -->
  <xsl:template match="/CUNIT_TEST_RUN_REPORT">
    <!-- Load coverage data from the external file -->
    <xsl:variable name="coverage" select="document('../build/coverage_report.xml')/coverage"/>
    
    <html>
      <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
        <title>Combined Test and Coverage Report</title>
      </head>
      <body>
        <h1>Combined Report</h1>
        
        <!-- Section 1: CUnit Test Report -->
        <h2>CUnit Test Report</h2>
        <!-- Display Test Suites -->
        <h3>Test Suites</h3>
        <xsl:apply-templates select="CUNIT_RESULT_LISTING/CUNIT_RUN_SUITE/CUNIT_RUN_SUITE_SUCCESS"/>
        
        <!-- Display Run Summary in a table -->
        <h3>Run Summary</h3>
        <table border="1" cellpadding="5" cellspacing="0">
          <tr>
            <th>Type</th>
            <th>Total</th>
            <th>Run</th>
            <th>Succeeded</th>
            <th>Failed</th>
            <th>Inactive</th>
          </tr>
          <xsl:apply-templates select="CUNIT_RUN_SUMMARY/CUNIT_RUN_SUMMARY_RECORD"/>
        </table>
        
        <!-- Footer information from CUnit report -->
        <div style="margin-top:20px;">
          <strong>Footer:</strong>
          <div>
            <xsl:value-of select="CUNIT_FOOTER"/>
          </div>
        </div>
        
        <!-- Section 2: Coverage Report -->
        <h2>Coverage Report</h2>
        <h3>Summary</h3>
        <table border="1" cellpadding="5" cellspacing="0">
          <tr>
            <th>Line Rate</th>
            <th>Branch Rate</th>
            <th>Lines Covered</th>
            <th>Lines Valid</th>
            <th>Branches Covered</th>
            <th>Branches Valid</th>
            <th>Complexity</th>
            <th>Version</th>
            <th>Timestamp</th>
          </tr>
          <tr>
            <td><xsl:value-of select="$coverage/@line-rate"/></td>
            <td><xsl:value-of select="$coverage/@branch-rate"/></td>
            <td><xsl:value-of select="$coverage/@lines-covered"/></td>
            <td><xsl:value-of select="$coverage/@lines-valid"/></td>
            <td><xsl:value-of select="$coverage/@branches-covered"/></td>
            <td><xsl:value-of select="$coverage/@branches-valid"/></td>
            <td><xsl:value-of select="$coverage/@complexity"/></td>
            <td><xsl:value-of select="$coverage/@version"/></td>
            <td><xsl:value-of select="$coverage/@timestamp"/></td>
          </tr>
        </table>
        
        <!-- Optional: Listing details for each package -->
        <h3>Coverage by Package</h3>
        <xsl:for-each select="$coverage/packages/package">
          <div style="margin-bottom:20px;">
            <h4>Package: <xsl:value-of select="@name"/></h4>
            <table border="1" cellpadding="5" cellspacing="0">
              <tr>
                <th>Line Rate</th>
                <th>Branch Rate</th>
                <th>Complexity</th>
              </tr>
              <tr>
                <td><xsl:value-of select="@line-rate"/></td>
                <td><xsl:value-of select="@branch-rate"/></td>
                <td><xsl:value-of select="@complexity"/></td>
              </tr>
            </table>
            <h5>Classes</h5>
            <table border="1" cellpadding="5" cellspacing="0">
              <tr>
                <th>Class Name</th>
                <th>Filename</th>
                <th>Line Rate</th>
                <th>Branch Rate</th>
              </tr>
              <xsl:for-each select="classes/class">
                <tr>
                  <td><xsl:value-of select="@name"/></td>
                  <td><xsl:value-of select="@filename"/></td>
                  <td><xsl:value-of select="@line-rate"/></td>
                  <td><xsl:value-of select="@branch-rate"/></td>
                </tr>
              </xsl:for-each>
            </table>
          </div>
        </xsl:for-each>
        
      </body>
    </html>
  </xsl:template>
  
  <!-- Template for each successful CUnit suite -->
  <xsl:template match="CUNIT_RUN_SUITE_SUCCESS">
    <div style="margin-bottom:20px;">
      <h4>Suite: <xsl:value-of select="SUITE_NAME"/></h4>
      <ul>
        <xsl:for-each select="CUNIT_RUN_TEST_RECORD/CUNIT_RUN_TEST_SUCCESS">
          <li>
            <xsl:value-of select="TEST_NAME"/>
          </li>
        </xsl:for-each>
      </ul>
    </div>
  </xsl:template>
  
  <!-- Template for each summary record -->
  <xsl:template match="CUNIT_RUN_SUMMARY_RECORD">
    <tr>
      <td><xsl:value-of select="TYPE"/></td>
      <td><xsl:value-of select="TOTAL"/></td>
      <td><xsl:value-of select="RUN"/></td>
      <td><xsl:value-of select="SUCCEEDED"/></td>
      <td><xsl:value-of select="FAILED"/></td>
      <td><xsl:value-of select="INACTIVE"/></td>
    </tr>
  </xsl:template>
  
</xsl:stylesheet>
