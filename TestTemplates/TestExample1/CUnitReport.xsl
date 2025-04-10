<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet 
    version="1.0" 
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <!-- Output configuration for HTML -->
  <xsl:output method="html" encoding="UTF-8" indent="yes"/>

  <!-- Match the document root -->
  <xsl:template match="/CUNIT_TEST_RUN_REPORT">
    <html>
      <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
        <title>CUnit Test Report</title>
      </head>
      <body>
        <h1>CUnit Test Report</h1>

        <!-- Process Test Suites -->
        <h2>Test Suites</h2>
        <xsl:apply-templates select="CUNIT_RESULT_LISTING/CUNIT_RUN_SUITE/CUNIT_RUN_SUITE_SUCCESS"/>

        <!-- Process the Run Summary -->
        <h2>Run Summary</h2>
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

        <!-- Display Footer -->
        <div style="margin-top:20px;">
          <strong>Footer:</strong>
          <div>
            <xsl:value-of select="CUNIT_FOOTER"/>
          </div>
        </div>
      </body>
    </html>
  </xsl:template>

  <!-- Template for each successful test suite -->
  <xsl:template match="CUNIT_RUN_SUITE_SUCCESS">
    <div style="margin-bottom:20px;">
      <h3>Suite: <xsl:value-of select="SUITE_NAME"/></h3>
      <ul>
        <!-- Iterate over each successful test record within the suite -->
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
