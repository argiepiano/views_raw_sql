Views Raw SQL
====

Views Raw SQL allows arbitrary SQL expressions to be added to Views, as fields and sorts. 

This is useful when you want to do something more complicated than Views or Views Calc can do already, e.g. sort by the sum of two fields multiplied by the square root of another field, and you've already built functionality around doing this in Views so it would be a pain to switch to a custom query.

**IMPORTANT**: Views Raw SQL expressions are __not__ safe. They can be used to circumvent data access restrictions with malicious SQL or to break a view with invalid SQL. So be very careful who you grant permission to use this module.

Installation
------------
Install this module using the official Backdrop CMS instructions at <https://backdropcms.org/guide/modules>.

Use
-----
A typical use of this module will look something like this:

1. In Views configuration, turn on the option to display query in preview.
2. Create a View that includes all of the fields you want to use in your SQL expressions. For example, if you want to add two number fields together, you first need to get the number fields loading. If you don't know how to do this, you shouldn't be using this module.
3. In the query preview, find the names of the fields you want to use. If you don't know how to read a SQL query, you shouldn't be using this module.
4. Add a new raw SQL field or sort, and write an expression that uses existing fields.
5. In the example, above, the raw SQL field looked like this

`(field_data_field_value_change_week.field_value_change_week_value / field_data_field_value.field_value_value) * SQRT(field_data_field_value.field_value_value)`

License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.

Maintainers
-----------

* argiepiano <https://github.com/argiepiano/>

Credits
-------

Drupal version currently maintained by:
* Beakerboy - https://www.drupal.org/u/beakerboy