<?php

/**
 * @file locations_views_handler_filter_specialties.inc
 * Basic "Location" equality filter handler 
 */

/**
 *
 */
class locations_views_handler_filter_specialties extends locations_views_handler_filter_equality {

  private static $specialties_defaults;
  static $specialties;
  
  static function initialize()
  {
    static::$specialties_defaults = array(
        'All' => '-Any-',
        '120' => 'Acute Inpatient Hospital',
	'7'   => 'Adult Medicine & Pediatrics',
        '8'   => 'Allergy & Immunology',
        '121' => 'Ambulatory Surgical Center',
        '122' => 'Anatomic & Clinical Pathology',
	'9'   => 'Anethesiology', 
	'160' => 'Asthma', 
	'10'  => 'Audiology', 
	'11'  => 'Bariatric Medicine', 
	'12'  => 'Behavioral Health', 
	'13'  => 'Behavioral Health, Pediatrics', 
	'14'  => 'Cardiac Electrophysiology', 
	'16'  => 'Cardiology', 
	'15'  => 'Cardiology, Interventional', 
	'17'  => 'Chiropractic', 
	'18'  => 'Critical Care Medicine', 
	'123' => 'Critical Care Services - Intensive Care Unit', 
	'19'  => 'Dentistry', 
	'20'  => 'Dermatology', 
	'159' => 'Diabetes', 
	'21'  => 'Diagnostic Radiology', 
	'124' => 'Dialysis', 
	'22'  => 'Dietician', 
	'125' => 'Durable Medical Equipment', 
	'158' => 'Ear Nose and Throat', 
	'23'  => 'Emergency Room', 
	'24'  => 'Endocrinology', 
	'25'  => 'Family Medicine', 
	'126' => 'Family Planning', 
	'127' => 'Federally Qualified Health Center', 
	'26'  => 'Fertility & Reproductive', 
	'27'  => 'Gastroenterology', 
	'28'  => 'Genetics', 
	'29'  => 'Geriatric Medicine', 
	'30'  => 'Gynecologic Oncology', 
	'31'  => 'Gynecology', 
	'128' => 'Health Department', 
	'32'  => 'Hematology & Oncology', 
	'129' => 'Home Health', 
	'130' => 'Home Infusion DME', 
	'131' => 'Hospice', 
	'132' => 'Hospital', 
	'33'  => 'Hospitalist', 
	'34'  => 'Hyperbaric Medicine', 
	'35'  => 'Immunology', 
	'36'  => 'Infectious Diseases', 
	'133' => 'Infusion Therapy', 
	'134' => 'Inpatient Psychiatric Facility', 
	'37'  => 'Intesivist', 
	'38'  => 'Interal Medicine', 
	'135' => 'Laboratory Services', 
	'136' => 'Mammography',
	'39'  => 'Maternal & Fetal Medicine', 
	'137' => 'Maternal Infant Health Program', 
	'138' => 'Mental Health',
	'40'  => 'Midwife, Certified', 
	'41'  => 'Neonatal/Perinatal Medicine', 
	'42'  => 'Neonatology', 
	'43'  => 'Nephrology', 
	'44'  => 'Neurology', 
	'45'  => 'Neurology, Child', 
	'46'  => 'Neuromusculoskeletal Medicine', 
	'47'  => 'Neurophysiology', 
	'48'  => 'Neuropsych', 
	'49'  => 'Neurosurgery', 
	'50'  => 'Nuclear Medicine', 
	'51'  => 'Nurse Practitioner', 
	'52'  => 'Obstetrics & Gynecology', 
	'59'  => 'Osteopathic Manipulative Medicine', 
	'60'  => 'Otolaryngology', 
	'143' => 'Outpatient Infusion/Chemotherapy',
	'144' => 'Outpatient Mental Health', 
	'145' => 'Outpatient Substance Abuse', 
	'61'  => 'Pain Medicine', 
	'62'  => 'Palliative Medicine', 
	'63'  => 'Pathology', 
	'64'  => 'Pediatric Allergy/Immunology', 
	'65'  => 'Pediatric Anesthesiology', 
	'66'  => 'Pediatric Cardiology', 
	'72'  => 'Pediatric Hospitalist', 
	'73'  => 'Pediatric Infectious Disease', 
	'74'  => 'Pediatric Nephrology', 
	'75'  => 'Pediatric Neurology', 
	'76'  => 'Pediatric NeuroPsych', 
	'77'  => 'Pediatric Opthamology', 
	'78'  => 'Pediatric Otolaryngology', 
	'79'  => 'Pediatric Pulmonology', 
	'80'  => 'Pediatric Rehabilitation Medicine', 
	'81'  => 'Pediatric Rheumatology',
	'82'  => 'Pediatric Surgery', 
	'83'  => 'Pediatric Urology', 
	'84'  => 'Pediatrics', 
	'157' => 'Pharmacy', 
	'85'  => 'Physical Medicine & Rehabilitation', 
	'146' => 'Physical Therapy', 
	'86'  => 'Physical Assistant', 
	'87'  => 'Plastic Therapy', 
	'88'  => 'Podiatry', 
	'89'  => 'Preventative Medicine', 
	'147' => 'Psychology', 
	'90'  => 'Pulmonology', 
	'91'  => 'Radiation Oncology', 
	'92'  => 'Radiology', 
	'93'  => 'Radiology, Interventional', 
	'94'  => 'Registerd Nurse', 
	'156' => 'Rehabilitation Center', 
	'95'  => 'Rheumatology', 
	'148' => 'Rural Health Clinic', 
	'149' => 'Skilled Nursing', 
	'96'  => 'Sleep Medicine', 
	'150' => 'Social Work', 
	'97'  => 'Speech Pathologist', 
	'151' => 'Speech Therapist', 
	'98'  => 'Sports Medicine', 
	'99'  => 'Surgery, Bariatric', 
	'100' => 'Surgery, Cardiothoracic',
	'101' => 'Surgery, Cardiovascular',
	'102' => 'Surgery, Colon & Rectal Surgery', 
	'103' => 'Surgery, Foot & Ankle', 
	'104' => 'Surgery, General',		
	'105' => 'Surgery, Hand', 
	'106' => 'Surgery, Oral & Maxillofacial', 
	'107' => 'Surgery, Orthopedic', 
	'108' => 'Surgery, Podiatric', 
	'109' => 'Surgery, Surgery Critical Care', 
	'110' => 'Surgery, Surgical Oncology', 
	'111' => 'Surgery, Thoracic', 
	'112' => 'Surgery, Thoracic Cardiovascular', 
	'113' => 'Surgery, Trauma Surgery',
	'114' => 'Surgery, Vascular Surgery', 
	'152' => 'Surgical Services', 
	'115' => 'Transfusion Medicine', 
	'116' => 'Transplant Surgery', 
	'153' => 'Tribal Health', 
	'154' => 'Urgent Care', 
	'117' => 'Urology', 
	'118' => 'Vascular Medicine', 
	'119' => 'Vascular Neurology', 
	'115' => 'Vision', 
      );
    
    self::setSpecialties(self::$specialties_defaults);
  }
  
  static function setSpecialties($newSpecialties)
  {
    static::$specialties = $newSpecialties;
  }

  /**
   * Provide the form for choosing specialties
   */
  function value_form(&$form, &$form_state) {
    if (!isset(static::$specialties)) static::initialize();
    
    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Specialties'),
      '#default_value' =>(!empty($this->value)) ? $this->value : 'All',
      '#options' => self:: $specialties,
    );

    if (!empty($form_state['exposed'])) {
      $identifier = $this->options['expose']['identifier'];
      if (!isset($form_state['input'][$identifier])) {
        $form_state['input'][$identifier] = $this->value;
      }
    }
  }

}

